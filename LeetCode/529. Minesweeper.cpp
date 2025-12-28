class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // draw(board);

        int m = board.size();
        if (m == 0) {return board;}
        int n = board[0].size();
        vector<vector<int>> stack;
        stack.push_back(click);
        vector<vector<int>> dir {
            {-1, 0}, {-1, -1}, {-1, 1},
            {1, 0}, {1, -1}, {1, 1},
            {0, 1}, {0, -1},
        };
        while(!stack.empty()) {
            vector<int>& back = stack.back();
            int x = back[0];
            int y = back[1];
            stack.pop_back();
            if (board[x][y] == 'M') {
                board[x][y] = 'X';
                break;
            }
            else if (board[x][y] == 'E') {
                int count = 0;
                for (int i = 0; i < dir.size(); ++i) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (board[nx][ny] == 'M') {
                            ++count;
                        }
                    }
                }
                if (count == 0) {
                    for (int i = 0; i < dir.size(); ++i) {
                        int nx = x + dir[i][0];
                        int ny = y + dir[i][1];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                            if (board[nx][ny] == 'E') {
                                stack.push_back({nx, ny});
                            }
                        }
                    }
                    board[x][y] = 'B';
                }
                else {
                    board[x][y] = '0' + count;
                }
            }
        }

        // draw(board);

        return board;
    }

    void draw(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};