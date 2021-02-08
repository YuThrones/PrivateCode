# 是上一道的简化版，做的顺序错了, 应该先做这道再做上一道好一点，现在的算法效率不够高，可能要考虑下优化。

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        adjust = defaultdict(set)
        
        adjust_check_set = set(wordList)
        adjust_check_set.add(beginWord)
        check_set = set(wordList)
        
        for check_word in adjust_check_set:
            size = len(check_word)
            for index in range(size):
                for char in range(26):
                    try_word = check_word[:index] + chr(97 + char) + check_word[index+1:]
                    if try_word in check_set and check_word != try_word:
                        adjust[check_word].add(try_word)
                        adjust[try_word].add(check_word)
        
        
        check_stack = [(beginWord, 1)]
        black_set = set()
        black_set.add(beginWord)
        while check_stack:
            top = check_stack.pop(0)
            word, level = top[0], top[1]
            if word == endWord:
                return level
            
            new_level = level + 1
            for try_word in adjust[word]:
                if try_word in black_set:
                    continue
                check_stack.append((try_word, new_level))
                black_set.add(try_word)
        
        return 0


# 也是跟126一样，使用两边往中间搜索的方式来降低复杂度，只是不需要再记录父节点，更加简单
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)

        if endWord not in wordSet:
            return 0
        
        beginSet = {beginWord}
        endSet = {endWord}

        lv=1

        while beginSet:
            wordSet -= beginSet
            lv+=1
            t=set()

            for w in beginSet:
                for i in range(len(w)):
                    l=w[:i]
                    r=w[i+1:]
                    
                    for c in string.ascii_lowercase:
                        n = l+c+r
                        
                        if n in wordSet:
                            if n in endSet:
                                return lv
                            else:
                                t.add(n)
            beginSet=t
            if len(beginSet)>len(endSet):
                endSet,beginSet = beginSet,endSet
        return 0