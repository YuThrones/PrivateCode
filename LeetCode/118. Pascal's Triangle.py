# 按照规律一行一行生成，注意判断上一行是否存在，以及左右父节点是否存在即可

class Solution:
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