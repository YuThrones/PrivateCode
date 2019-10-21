这道题比较简单，只是要注意一个陷阱，要先记录哪些行列为0，然后统一设置，不能一边遍历一边设置，因为可能本来已经为0，会丢失信息
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        zero_col = {}
        zero_row = {}
        for r, r_list in enumerate(matrix):
            for c, c_num in enumerate(r_list):
                if (c_num == 0):
                    zero_col[c] = 1
                    zero_row[r] = 1
        for r, r_list in enumerate(matrix):
            for c, c_num in enumerate(r_list):
                if (r in zero_row or c in zero_col):
                    matrix[r][c] = 0
        