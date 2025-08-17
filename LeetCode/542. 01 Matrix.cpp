class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat);
        queue<vector<int>> q;

        for (int i = 0; i < mat.size(); ++i) {
            
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    ans[i][j] = 0;
                }
                else {
                    ans[i][j] = -1;
                }
            }
        }

        vector<vector<int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while(!q.empty()) {
            vector<int> front = q.front();
            q.pop();
            int i = front[0];
            int j = front[1];
            int dep = front[2];
            for (auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[0].size() && ans[ni][nj] == -1){
                    ans[ni][nj] = dep + 1;
                    q.push({ni, nj, dep + 1});
                }
            }
        }

        return ans;
    }
};