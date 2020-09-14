# 直接用上道题的代码，然后只返回最后一行就可以，如果要节省空间，可以只保存两行

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        return self.generate(rowIndex+1)[-1]
        
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for row in range(numRows):
            last_row = row - 1

            res.append([])
            if (last_row < 0):
                res[row].append(1)
                continue
            
            last_length = len(res[last_row])
            for col in range(row + 1):
                last_left = col - 1
                last_right = col
                if (last_left >= 0 and last_right < last_length):
                    res[row].append(res[last_row][last_left] + res[last_row][last_right])
                else:
                    res[row].append(1)
            
        return res