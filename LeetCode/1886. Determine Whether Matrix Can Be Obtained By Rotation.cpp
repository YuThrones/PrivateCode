// 直接生产一个旋转的矩阵好像更方便，不过理论上应该没有傻瓜比较快

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for (int i = 0; i < 4; i++) {
            if (mat == target) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};


class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        return is0(mat, target) || is90(mat, target) || is180(mat, target) || is270(mat, target);
    }

    bool is0(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool is90(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (mat[i][j] != target[j][n - 1 - i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool is180(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool is270(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (mat[i][j] != target[n - 1 - j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};