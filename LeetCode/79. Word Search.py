# 基本思路是深度优先搜索，不过我这么写效率不够高，而且不好理解，我看了下其他的答案，有java的实现是直接利用board，不需要像我一样维护可选的列表
# 直接使用board，用一个字符占掉已经使用的格子，然后使用递归继续搜索，更方便理解，效率也高很多
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        dir_list = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        stack = []
        wordlen = len(word)
        rowlen = len(board)
        collen = len(board[0])
        
        for row_index, row in enumerate(board):
            for col_index, col in enumerate(row):
                if (col != word[0]):
                    continue
                stack = []
                for _ in range(wordlen):
                    stack.append([])
                stack[0] = [(row_index, col_index)]
                cur = 0
                use_list = []
                
                while(cur >= 0):
                    # print(stack, use_list)
                    toplist = stack[cur]
                    if (len(toplist) <= 0):
                        cur -= 1
                        if (len(use_list) > 0):
                            use_list.pop()
                        continue
                    
                    top = toplist.pop()
                    
                    cur += 1
                    use_list.append(top)
                    if (cur == len(word)):
                        return True
                    
                    new_top_list = []
                    for direct in dir_list:
                        new_row, new_col = top[0] + direct[0], top[1] + direct[1]
                        if (new_row < 0 or new_row >= rowlen or new_col < 0 or new_col >= collen):
                            continue
                        if ((new_row, new_col) in use_list):
                            continue
                        if (board[new_row][new_col] == word[cur]):
                            new_top_list.append((new_row, new_col))
                    stack[cur] = new_top_list
                        
        return False
                        
# 这个是递归版本，更加简洁             
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for row_index, row in enumerate(board):
            for col_index, col in enumerate(row):
                if (self.check(board, row_index, col_index, 0, word)):
                    return True
        return False
                
                
    def check(self, board, row, col, index, word):
        # print(board, row, col, index, word)
        if (index == len(word)):
            return True
        if (row < 0 or col < 0 or row >= len(board) or col >= len(board[0])):
            return False
        temp = board[row][col]
        if (temp != word[index]):
            return False
        board[row][col] = "#"
        result = self.check(board, row - 1, col, index + 1, word) or \
            self.check(board, row + 1, col, index + 1, word) or \
            self.check(board, row, col - 1, index + 1, word) or \
            self.check(board, row, col + 1, index + 1, word)
        board[row][col] = temp
        return result
            
                
                