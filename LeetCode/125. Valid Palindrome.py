# 比较简单，只需要注意有效参数的定义只有字母和数字，先做一遍预处理把无效参数剔除即可
class Solution:
    def isPalindrome(self, s: str) -> bool:
        str_list = []
        for sub in s:
            if sub == ' ':
                continue
            if sub >= 'a' and sub <= 'z' or sub >= 'A' and sub <= 'Z':
                str_list.append(sub.upper())
            elif sub >= '0' and sub <= '9':
                str_list.append(sub)

        for index in range(len(str_list) // 2):
            if str_list[index] != str_list[-index-1]:
                return False

        return True