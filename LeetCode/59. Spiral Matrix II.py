# 跟之前的矩阵一样，注意边界就可以
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = []
        for i in range(n):
            row = []
            for j in range(n):
                row.append(0)
            result.append(row)
        count = 1
        for round_count in range(n // 2):
            for i in range(round_count, n - round_count):
                result[round_count][i] = count
                # print (round_count, i)
                count += 1
            
            for i in range(round_count + 1, n - round_count):
                result[i][n - 1 -round_count] = count
                # print (i, n - 1 -round_count)
                count += 1
                
            for i in range(n - 2 - round_count, round_count - 1, -1):
                result[n - 1 - round_count][i] = count
                # print (n - 1 - round_count, i)
                count += 1
                
            for i in range(n - 2 - round_count, round_count, -1):
                # print (i,n - 2 - round_count)
                result[i][round_count] = count
                count += 1
        if (n%2 == 1):
            result[n // 2][n // 2] = n * n
        return result