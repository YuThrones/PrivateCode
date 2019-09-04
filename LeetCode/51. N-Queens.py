# 典型的八皇后问题，思路也比较清晰，逐行遍历，尝试每行中的可能皇后位置，深度优先搜索找到可能的解
# 记录每列，每个左斜对角线和右斜对角线是否冲突，就可以解决问题
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.col_dict = set()
        self.left_dict = set()
        self.right_dict = set()
        self.current_list = []
        self.result = []
        self.solve(0, n)
        result = []
        for r in self.result:
            l = []
            for row in range(n):
                sl = ["."] * n
                sl[r[row]] = "Q"
                l.append("".join(sl))
            result.append(l)
        return result
        
    def solve(self, row, n):
        if (row == n):
            self.result.append(tuple(self.current_list))
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

    
    