# 就是一个查重问题而已，唯一注意的就是不要想太多，他不要求数独可解。。。。
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
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
                    if (col in row_dict[row_num]):
                        return False
                    if (col in col_dict[col_num]):
                        return False
                    box_num = self.GetBox(row_num, col_num)
                    if (col in box_dict[box_num]):
                        return False
                    row_dict[row_num].add(col)
                    col_dict[col_num].add(col)
                    box_dict[box_num].add(col)
        return True
                
    def GetBox(self, row_num, col_num):
        return row_num // 3 * 3 + col_num // 3