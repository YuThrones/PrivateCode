这个解法是从discuss看到的，核心思想是，如果没遇到*就正常比较，遇到*就记录最后一个*的位置，然后继续往后比较，如果遇到没法匹配成功的，就检查是否有记录*的位置
如果有，就用这个位置回溯，并且重置在原字符串的游标
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        star_pos = -1
        ss_pos = -1
        s_index = 0
        p_index = 0
        p_length = len(p)
        s_length = len(s)
        while(s_index < s_length):
            if (p_index < p_length):
                if (p[p_index] == s[s_index] or p[p_index] == "?"):
                    p_index += 1
                    s_index += 1
                    continue

                 # 这个star_pos 和 ss_pos的作用是回溯，等到不满足条件回到*号这里重新找
                if (p[p_index] == "*"):
                    star_pos = p_index
                    p_index += 1
                    ss_pos = s_index
                    continue
                
            if (star_pos != -1):
                p_index = star_pos + 1
                ss_pos += 1
                s_index = ss_pos
                continue
                
            return False
        
        while(p_index < p_length and p[p_index] == "*"):
            p_index += 1
        
        return p_index == p_length