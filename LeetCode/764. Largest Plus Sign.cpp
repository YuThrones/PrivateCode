最佳答案只用了一个矩阵，更加简洁，常数时间更快。

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(n*n == mines.size())
            return 0;
        
        int t[n][n];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j] = n;
            }
        }
        
        for(vector<int>& vec : mines)
            t[vec[0]][vec[1]] = 0;
        
        int ans = 0;
        
        for(int i = 0; i<n; i++) {
            //t[][] will be updated to minimum of its left, right, up and down (count of 1s)
            
            //Look for longest streak of 1 at its left
            int left = 0;
            for(int j = 0; j < n; j++) {
                left = t[i][j] == 0 ? 0 : left+1;
                t[i][j] = min(t[i][j], left);
            }
            
            //Look for longest streak of 1 at its right
            int right = 0;
            for(int j = n-1; j>=0; j--) {
                right = t[i][j] == 0 ? 0 : right+1;
                t[i][j] = min(t[i][j], right);
            }
            
            //Look for longest streak of 1 at its up
            int up = 0;
            for(int k = 0; k < n; k++) {
                up = t[k][i] == 0 ? 0 : up+1;
                t[k][i] = min(t[k][i], up);
            }
            
            //Look for longest streak of 1 at its down
            int down = 0;
            for(int k = n-1; k >= 0; k--) {
                down = t[k][i] == 0 ? 0 : down+1;
                t[k][i] = min(t[k][i], down);
            }
        }
        
        //Finally, find the max one
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, t[i][j]);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> data(n, vector<int>(n, 1));
        for(auto& m : mines) {
            data[m[0]][m[1]] = 0;
        }
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (data[i][j] && i > 0) {
                    left[i][j] = left[i - 1][j] + 1;
                }
                else {
                    left[i][j] = data[i][j];
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (data[i][j] && j > 0) {
                    up[i][j] = up[i][j - 1] + 1;
                }
                else {
                    up[i][j] = data[i][j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (data[i][j] && j + 1 < n) {
                    right[i][j] = right[i][j + 1] + 1;
                }
                else {
                    right[i][j] = data[i][j];
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                if (data[i][j] && i + 1 < n) {
                    down[i][j] = down[i + 1][j] + 1;
                }
                else {
                    down[i][j] = data[i][j];
                }
            }
        }
        int len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp = n;
                temp = min(temp, up[i][j]);
                temp = min(temp, down[i][j]);
                temp = min(temp, left[i][j]);
                temp = min(temp, right[i][j]);
                len = max(temp, len);
            }
        }
        return len;
    }
};