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
                

# 看了下其他人的答案，更快的解法是，只从最边缘的四条边中的O开始搜索，把与这部分O相连的全部标记为第三种标记，比如N，在全部标记完之后，就可以看到，只要是标记为N的都不需要转换
# 依然是O的标记的，证明没有跟外围相连，是被包围的，把O转为X，N转为O即可
# 这种做法还节省了一个用来标记已经访问的set，无论从时间还是空间上都更优

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # guard clause
        if not board or not board[0]:
            return
        
        R = len(board)
        C = len(board[0])
        
        # guard clause
        if R <= 2 or C <= 2:
            return
        
        def dfs(board, r, c, R, C): # dfs when find a "O" change to something diff and recurse
            if 0 <= r < R and 0 <= c < C and board[r][c] == "O":
                board[r][c] = "N"
                dfs(board, r, c+1, R, C)
                dfs(board, r, c-1, R, C)            
                dfs(board, r-1, c, R, C)            
                dfs(board, r+1, c, R, C) 
                
                
        for r in range(R): # loop rows and recurse changing all "O" to "N"s
            dfs(board, r, 0, R, C)
            dfs(board, r, C-1, R, C)
        
        for c in range(C): # loop cols and recurse changing all "O" to "N"s
            dfs(board, 0, c, R, C)
            dfs(board, R-1, c, R, C)
            
        # go thru board, change all N's to Os and any remaining O's to X's
        for r in range(R):
            for c in range(C): 
                if board[r][c] == "O":
                    board[r][c] = "X"
                if board[r][c] == "N":
                    board[r][c] = "O"