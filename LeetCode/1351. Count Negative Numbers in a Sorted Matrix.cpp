class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        if (m == 0) {
            return count;
        }
        int n = grid[0].size();
        int total = m * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // cout << i << " " << j << " " <<grid[i][j] << endl;
                if (grid[i][j] >= 0) {
                    ++count;
                }
                else {
                    n = j;
                    break;
                }
            }
        }
        return total - count;
    }
};