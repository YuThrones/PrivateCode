// 这道题和核心在于
// 行的交换不会改变行内部结构，列的交换不会改变列的内部结构
// 要保证有答案，所有行要么与第一行相同，要么与第一行互补，列也一样
// 在检查了行列的奇偶性，还有1的数量符合要求之后，只需要对第一行和第一列做计算，保证他们调整好奇偶性就行

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        
        int n = board.size();
        if (n <= 1) {
            return 0;
        }
        for(int i = 1; i < n; ++i) {
            bool bSame = board[i][0] == board[0][0];
            for(int j = 0; j < n; ++j) {
                if (bSame) {
                    if (board[i][j] != board[0][j]) {
                        return -1;
                    }
                }
                else {
                    if (board[i][j] == board[0][j]) {
                        return -1;
                    }
                }
            }
        }

        for(int i = 1; i < n; ++i) {
            bool bSame = board[0][i] == board[0][0];
            for(int j = 0; j < n; ++j) {
                if (bSame) {
                    if (board[j][i] != board[j][0]) {
                        return -1;
                    }
                }
                else {
                    if (board[j][i] == board[j][0]) {
                        return -1;
                    }
                }
            }
        }

        vector<int> row;
        for(int i = 0; i < n; ++i) {
            row.push_back(board[0][i]);
        }
        vector<int> col;
        for(int i = 0; i < n; ++i) {
            col.push_back(board[i][0]);
        }
        int rowOnes = accumulate(row.begin(), row.end(), 0);
        if (abs(rowOnes * 2 - n) > 1) return -1;

        int colOnes = accumulate(col.begin(), col.end(), 0);
        if (abs(colOnes * 2 - n) > 1) return -1;
        return minSwap(row, n) + minSwap(col, n);

    }

    int minSwap(vector<int>& arr, int n) {
        int diff = 0;
        for(int i = 0; i < n; ++i) {
            if (i % 2 != arr[i]) {
                ++diff;
            }
        }

        if(n % 2 == 0) {
            return min(diff, n - diff) / 2;
        }
        else {
            int ones = 0;
            for(int i = 0; i < n; ++i) {
                ones += arr[i];
            }
            if (ones * 2 > n) {
                return (n - diff) / 2;
            }
            else {
                return diff / 2;
            }
        }
        return -1;
    }
};