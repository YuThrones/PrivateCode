# 思路是比较简单的，模拟他的前进轨迹，判断好边界条件即可
# 看了下答案，这个写法还可以优化，把从(r1,c1)到(r1,c2)封装成函数，并且方向用数组表示，可以省略很大一部分代码

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        row_len = len(matrix)
        if (row_len == 0):
            return  []
        col_len = len(matrix[0])
        if (col_len == 0):
            return []
        times = row_len * col_len
        side = 0
        count = 0
        result = []
        row = col = 0
        round_count = 0
        while (count < times):
            result.append(matrix[row][col])
            if (side == 0):
                if (col < col_len - 1 - round_count):
                    col += 1
                else:
                    row += 1
                    side = 1
            elif (side == 1):
                if (row < row_len - 1 - round_count):
                    row += 1
                else:
                    col -= 1
                    side = 2
                    
            elif (side == 2):
                if (col > round_count):
                    col -= 1
                else:
                    row -= 1
                    side = 3
            else:
                if (row > round_count + 1):
                    row -= 1
                else:
                    col += 1
                    side = 0
                    round_count += 1
                
            count += 1
            
        return result