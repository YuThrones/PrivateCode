// 我的想法是遍历，记录走过的格子，然后四个方向找，复杂度是O(n)，不过代码多了点
// 看了下最佳答案，他们更好的利用了条件，只寻找第一个X，必然是在左上角，只要是X，而且上面或者左边不是X，那就是区域起点，确实更加优雅

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;

        for (int y = 0; y < board.size(); y++) {
            const vector<char>& row = board[y];
            for (int x = 0; x < row.size(); x++) {
                if (row[x] == 'X'
                        && (x == 0 || row[x - 1] != 'X')
                        && (y == 0 || board[y - 1][x] != 'X')) {
                    result++;
                }
            }
        }

        return result;
    }
};

#include <vector>

using namespace std;

int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int rowSize = board.size();
        if (!rowSize) return res;
        int colSize = board[0].size();
        if (!colSize) return res;
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (board[i][j] != 'X') continue;
                ++res;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirX[k];
                    int y = j + dirY[k];
                    while(x >= 0 && y >= 0 && x < rowSize && y < colSize) {
                        if (visited[x][y]) break;
                        visited[x][y] = true;
                        if (board[x][y] != 'X') break;
                        x += dirX[k];
                        y += dirY[k];
                    }
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    // vector<vector<char>> board({{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}});
    vector<vector<char>> board({{'X','.','X'}});
    s.countBattleships(board);
    return 0;
}