# 这道题要注意题意，数组中每个str长度是相等的，这一点很关键。最简单的做法是暴力破解，但是复杂度太高。下面的解法是从其他版本的优解看到的，
# 核心思路是维护一个窗口，如果当前窗口增加了一个新的str之后无法满足条件，就从窗口的最左边开始往右挪，直到不违反窗口中的str都在给定数组中
# 且数量不超过给定数组，通过维护窗口减少重复检查s的同一个位置。
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        if (len(s) <= 0 or len(words) <= 0):
            return ans
        search_dict = {}
        for sub in words:
            if (not sub in search_dict):
                search_dict[sub] = 1
            else:
                search_dict[sub] += 1
        list_size = len(words)
        length = len(s)
        size = len(words[0])
        # print ("search", search_dict)
        for init_start in range(size):
            start = init_start
            repeat_dict = {}
            count = 0
            current = start
            while(current < length):
                sub_str = s[current:current+size]
                # print (start, current, repeat_dict, sub_str)

                if (sub_str in search_dict):
                    if (not sub_str in repeat_dict):
                        repeat_dict[sub_str] = 0
                    
                    while (repeat_dict[sub_str] + 1 > search_dict[sub_str] and count > 0):
                        repeat_dict[s[start:start+size]] -= 1
                        count -= 1
                        # print ("sub", start, repeat_dict, count)
                        start += size

                                
                    repeat_dict[sub_str] += 1
                    count += 1
                    current += size
                    # print ("add", current)
                    if (count == list_size):
                        ans.append(start)
                else:
                    repeat_dict = {}
                    count = 0
                    current += size
                    start = current
                    # print ("reset", start,current)

        return ans