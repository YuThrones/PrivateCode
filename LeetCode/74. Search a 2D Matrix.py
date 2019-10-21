# 本质上是一道二分搜索，只是把一个列表分成了多行，可以当一个列表搜，做一下坐标转化，也可以先二分搜索到行，然后对行再次二分搜索，如果把GetIndex函数直接拿出来放进去，效率应该会更高一点
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = len(matrix)
        if (row == 0):
            return False
        col = len(matrix[0])
        
        total = row * col
        # print (row, col, total)
        
        def GetIndex(index):
            return index // col, index % col
        
        min_index = 0
        max_index = total - 1
        while(min_index <= max_index):
            mid = (min_index + max_index) // 2
            r, c = GetIndex(mid)
            # print(min_index, max_index, mid, r, c)
            if (matrix[r][c] == target):
                return True
            if (matrix[r][c] < target):
                min_index = mid + 1
            else:
                max_index = mid - 1
        return False