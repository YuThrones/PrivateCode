class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0) {return 0;}
        int c = grid[0].size();
        for(int i = 0; i < r; ++i) {
            if (grid[i][0] == 0) {
                for(int j = 0; j < c; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        for(int j = 1; j < c; ++j) {
            int count = 0;
            for(int i = 0; i < r; ++i) {
                count += grid[i][j];
            }
            if (count * 2 < r) {
                for(int i = 0; i < r; ++i) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < r; ++i) {
            int temp = 0;
            for(int j = 0; j < c; ++j) {
                temp = temp * 2 + grid[i][j];
            }
            ans += temp;
        }
        return ans;
    }
};