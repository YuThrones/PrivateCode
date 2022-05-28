// 没什么技术含量，纯coding题，最快解法的优化是，不适用第二个vector，而是通过设置为不同状态，来保存周围存活个数的同时，让周围能读到自己原始状态

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board1;
        for (int i = 0; i < board.size(); ++i) {
            board1.push_back(vector<int>(board[i].size(), 0));
            for (int j = 0; j < board[i].size(); ++j) {
                board1[i][j] = board[i][j];
            }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int count = 0;
                if (i - 1 >= 0 && board1[i - 1][j]) ++count;
                if (i - 1 >= 0 && j - 1 >= 0 && board1[i - 1][j - 1]) ++count;
                if (i - 1 >= 0 && j + 1 < board1[i].size() && board1[i - 1][j + 1]) ++count;
                if (j - 1 >= 0 && board1[i][j - 1]) ++count;
                if (j + 1 < board1[i].size() && board1[i][j + 1]) ++ count;
                if (i + 1 < board1.size() && j - 1 >= 0 && board1[i + 1][j - 1]) ++count;
                if (i + 1 < board1.size() && board1[i + 1][j]) ++count;
                if (i + 1 < board1.size() && j + 1 < board1[i].size() && board1[i + 1][j + 1]) ++count;


                if (board1[i][j]) {
                    if (count < 2 || count > 3) board[i][j] = 0;
                }
                else {
                    if (count == 3) board[i][j] = 1;
                }
                // cout << i << " " << j << " " << board1[i][j] << " " << count << " " << board[i][j] << endl;

            }
        }
    }
};