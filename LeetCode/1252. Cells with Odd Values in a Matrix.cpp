class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (auto& ind : indices) {
            row[ind[0]]++;
            col[ind[1]]++;
        }

        int result = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if ((row[r] + col[c]) % 2 == 1) {
                    ++result;
                }
            }
        }
        return result;
    }
};