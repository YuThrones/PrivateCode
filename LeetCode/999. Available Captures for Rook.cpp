class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        vector<vector<int>> dir {
            {-1, 0}, {1, 0},
            {0, -1}, {0, 1},
        };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'R') {

                    for (auto& d: dir) {
                        int x = i + d[0];
                        int y = j + d[1];
                        while (x >= 0 
                                && x < board.size() 
                                && y >= 0 
                                && y < board[0].size()) {
                            if (board[x][y] == 'p') {
                                ++ans;
                                break;
                            }
                            if (board[x][y] == 'B') {
                                break;
                            }
                            x += d[0];
                            y += d[1];
                        }

                    }
                    break;
                }

            }
        }
        return ans;
    }
};