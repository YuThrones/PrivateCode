# 思路很简单，三个字典记录重复，然后深度优先搜索就可以
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row_dict = {}
        col_dict = {}
        box_dict = {}
        for index in range(9):
            row_dict[index] = set()
            col_dict[index] = set()
            box_dict[index] = set()
        
        result = False
        for row_num, row in enumerate(board):
            for col_num, col in enumerate(row):
                if (col != "."):
                    row_dict[row_num].add(col)
                    col_dict[col_num].add(col)
                    box_dict[self.GetBox(row_num, col_num)].add(col)
        self.search(board, 0, 0, row_dict, col_dict, box_dict)
        return
    
    def search(self, board, row_num, col_num, row_dict, col_dict, box_dict):
        # print (board, row_num, col_num)
        if (row_num == 9 and col_num == 0):
            return True
        check_num = board[row_num][col_num]
        box_num = self.GetBox(row_num, col_num)
        
        if (col_num + 1 == 9):
            next_row, next_col = row_num + 1, 0
        else:
            next_row, next_col = row_num, col_num + 1

        if (check_num != "."):
            return self.search(board, next_row, next_col, row_dict, col_dict, box_dict)
        else:
            for test in range(1, 10):
                try_num = str(test)
                if ((try_num in row_dict[row_num]) 
                    or (try_num in col_dict[col_num]) 
                    or (try_num in box_dict[box_num])):
                    continue
                row_dict[row_num].add(try_num)
                col_dict[col_num].add(try_num)
                box_dict[box_num].add(try_num)
                result = self.search(board, next_row, next_col, row_dict, col_dict, box_dict)
                if (result):
                    board[row_num][col_num] = try_num
                    return True
                row_dict[row_num].remove(try_num)
                col_dict[col_num].remove(try_num)
                box_dict[box_num].remove(try_num)
        return False
                
    def GetBox(self, row_num, col_num):
        return row_num // 3 * 3 + col_num // 3