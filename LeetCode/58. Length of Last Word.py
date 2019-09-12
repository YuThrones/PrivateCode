# 倒序遍历，注意下边界条件就可以了
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = len(s)
        find_index = -1
        for index in range(length - 1, -1, -1):
            if (s[index] == " "):
                if (find_index != -1):
                    return find_index - index
            else:
                if (find_index == -1):
                    find_index = index
        if (find_index == -1):
            return 0
        else:
            return find_index + 1
        