# 有两种思路，一种是统计字母个数，用不同字母的统计值做hash，另一种是字母重新排序，然后用有序str作key，都是NK复杂度，实测效果没多大车别
class Solution:
    def groupAnagrams(self, strs):
        ans = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            ans[tuple(count)].append(s)
        return ans.values()