class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int len = 1;
        vector<vector<int>> dir {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        };
        int dirIndex = 0;
        vector<int> curDir = dir[dirIndex];
        int r = rStart;
        int c = cStart;
        ans.push_back({r, c});
        while(ans.size() < rows * cols) {
            for(int j = 0; j < 2; ++j) {
                for(int i = 0; i < len; ++i) {
                    r += curDir[0];
                    c += curDir[1];
                    if(r >= 0 && r < rows && c >= 0 && c < cols) {
                        ans.push_back({r, c});
                        if(ans.size() == rows * cols) {
                            return ans;
                        }
                    }
                }
                dirIndex = (dirIndex + 1) % 4;
                curDir = dir[dirIndex];
            }
            ++len;
        }
        return ans;
    }
};