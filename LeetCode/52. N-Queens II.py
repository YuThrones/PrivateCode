# 跟上道题没啥区别，只是返回的结果是数量     
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.col_dict = set()
        self.left_dict = set()
        self.right_dict = set()
        self.current_list = []
        self.result = 0
        self.solve(0, n)
        return self.result
        
    def solve(self, row, n):
        if (row == n):
            self.result += 1
        for try_num in range(n):
            if (try_num in self.col_dict):
                continue
            left = row - try_num
            right = row + try_num
            if (left in self.left_dict):
                continue
            if (right in self.right_dict):
                continue
            self.current_list.append(try_num)
            self.col_dict.add(try_num)
            self.left_dict.add(left)
            self.right_dict.add(right)

            self.solve(row + 1, n)
            self.current_list.remove(try_num)
            self.col_dict.remove(try_num)
            self.left_dict.remove(left)
            self.right_dict.remove(right)

    
    