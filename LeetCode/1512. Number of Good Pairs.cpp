class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += mat[i][i];
            if (i * 2 != (n - 1)) {
                ans += mat[i][n - 1 - i];
            }
        }
        return ans;
    }
};