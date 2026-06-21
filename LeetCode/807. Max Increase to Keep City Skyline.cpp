class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rH(n, 0);
        vector<int> cH(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                rH[i] = max(rH[i], grid[i][j]);
                cH[j] = max(cH[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = min(rH[i], cH[j]);
                ans += (temp - grid[i][j]);
            }
        }
        return ans;
    }
};