# 比较正常的思路，遍历所有的格子，然后找到O格子相连的所有O格子，并且在遍历过程中判断有没有触碰到边界，如果没有，则说明会被X包围，需要被转换
# 每个格子会被检查一次，复杂度大致为n的平方

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        if not board:
            return
        
        if len(board) == 0:
            return
        
        black_set = set()
        dir_list = ((-1, 0), (1, 0), (0, -1), (0, 1))
        
        row_len = len(board)
        col_len = len(board[0])
        
        for row_index in range(row_len):
            for col_index in range(col_len):
                if board[row_index][col_index] == 'X' or (row_index, col_index) in black_set:
                    continue
                    
                stack = [(row_index, col_index)]
                pos_list = [(row_index, col_index)]
                black_set.add((row_index, col_index))
                can_change = True
                while stack:
                    pos = stack.pop(-1)
                    for check_dir in dir_list:
                        check_row, check_col = pos[0] + check_dir[0], pos[1] + check_dir[1]
                        
                        if check_row < 0 or check_row >= row_len or check_col < 0 or check_col >= col_len:
                            can_change = False
                            continue
                        
                        if board[check_row][check_col] == 'X' or (check_row, check_col) in black_set:
                            continue
                        black_set.add((check_row, check_col))
                        stack.append((check_row, check_col))
                        pos_list.append((check_row, check_col))
                
                if can_change:
                    for pos in pos_list:
                        board[pos[0]][pos[1]] = 'X'
                