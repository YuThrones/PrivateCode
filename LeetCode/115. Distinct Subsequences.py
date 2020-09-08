# 最开始的想法是使用子问题分解递归，尝试匹配s和t在某个位置的字符，如果相等，则派生出一颗子树来解决后面的子问题，写了一下，发现超时，原因是很多子问题可能被重复解答
# 看了下讨论的解法，是使用DP来解决，跟我的递归思路相似，但是状态的划分更合理，解决前面的问题可以为后面服务
# 主要思路是，使用矩阵record[len(s) + 1][len(t) + 1]来存储s的子字符串包含t的子字符串的个数
# record[i+1][j+1] 表示字符串s[:i] 包含字符串t[:j]，record[i+1][j+1]的值取决于record[i][j+1] 和 record[i][j] 的值
# 如果s[:i-1]包含t[:j]，必然有s[:i]包含t[:j]
# 如果s[i]等于t[j]，这种情况下取值则是使用s[i-1]包含t[j-1]的结果
# 因此就是取上述两种情况的和

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        record = []
        len_s = len(s)
        len_t = len(t)
        for i in range(len_s + 1):
            record.append([])
            for j in range(len_t + 1):
                if (j == 0):
                    record[i].append(1)
                else:
                    record[i].append(0)
                    
        for s_index, s_str in enumerate(s):
            for t_index, t_str in enumerate(t):
                if (s_str == t_str):
                    record[s_index + 1][t_index + 1] = record[s_index][t_index] + record[s_index][t_index + 1]
                else:
                    record[s_index + 1][t_index + 1] = record[s_index][t_index + 1]
                    
        # print("打印矩阵", record)
        
        return record[len_s][len_t]