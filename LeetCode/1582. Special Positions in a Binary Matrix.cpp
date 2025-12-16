class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) {return 0;}
        int n = mat[0].size();
        if (n == 0) {return 0;}
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; ++i) {
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {++temp;}
            }
            row[i] = temp;
        }
        for (int j = 0; j < n; ++j) {
            int temp = 0;
            for(int i = 0; i < m; ++i) {
                if (mat[i][j] == 1) {++temp;}
            }
            col[j] = temp;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};