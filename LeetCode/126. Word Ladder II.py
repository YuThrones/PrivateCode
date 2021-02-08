# 第一时间想到的就是用广度优先搜索然后加剪枝，确实能解出来，但是好像不够快

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if not endWord in wordList:
            return []
        last_word = {}
        stack = [beginWord]
        res_list = []
        check_list = wordList
        black_set = set()
        gray_set = set()
        level_dict = {beginWord:1}
        while (stack):
            first = stack.pop(0)
            black_set.add(first)
    
            check_list.append(first)
            remove_list = []
            
            clear_list = False
            for word in check_list:
                if first == word:
                    continue
                if word in level_dict and level_dict[word] <= level_dict[first]:
                    remove_list.append(word)
                    continue
                if self.isNear(first, word):
                    last_word.setdefault(word, [])
                    last_word[word].append(first)
                    level_dict[word] = level_dict[first] + 1
                    if word == endWord:
                        clear_list = True
                        break
                    if not word in gray_set:
                        stack.append(word)
                        gray_set.add(word)
            
            if clear_list:
                check_list = [endWord]
            else:
                for rem in remove_list:
                    check_list.remove(rem)

        if endWord not in last_word:
            return []
        res_list = self.find_path(last_word, endWord)
        num2list = {}
        minnum = None
        for res in res_list:
            length = len(res)
            num2list.setdefault(length, [])
            num2list[length].append(res)
            if minnum is None or length < minnum:
                minnum = length
        
        # print ('全列表', last_word)
        # print ('结果', num2list[minnum])
        return num2list[minnum]
        
    def isNear(self, first, second):
        diff = 0
        for index in range(len(first)):
            if first[index] != second[index]:
                diff += 1
            if diff > 1:
                return False
        return diff == 1
    
    def find_path(self, last_word, endWord):
        if not endWord in last_word:
            return [[endWord]]
        
        res = []
        for sub_word in last_word[endWord]:
            sub_res = self.find_path(last_word, sub_word)
            for sub in sub_res:
                sub.append(endWord)
                res.append(sub)
        return res


# 看到的最快的Submissions，稍微难理解一点，做法是从beginWord和endWord两端往中间搜索，一旦找到两个搜索集合的交集，就认为已经找到最短的路径，然后计算路径
# 最后的运行速度快了一个数量级，以后可以借鉴下
from collections import defaultdict, deque
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        s = set(wordList)
        if endWord not in s: 
            return []
        
        forward, backward = {beginWord}, {endWord} 
        direc, parents = 1, defaultdict(set)
        
        while forward and backward: 
            if len(forward) > len(backward): 
                forward, backward = backward, forward 
                direc *= -1 
            s -= forward 
            next_forward = set()
            
            for word in forward: 
                for i in range(len(word)): 
                    p1, p2 = word[:i], word[i+1:]
                    for c in string.ascii_lowercase: 
                        t = p1 + c + p2
                        if t in s: 
                            next_forward.add(t)
                            if direc == 1: 
                                parents[t].add(word)
                            else: 
                                parents[word].add(t)
            if backward & next_forward: 
                res = [[endWord]]
                while res[0][0] != beginWord: 
                    res = [[p]+r for r in res for p in parents[r[0]]]
                return res
            forward = next_forward
        return []