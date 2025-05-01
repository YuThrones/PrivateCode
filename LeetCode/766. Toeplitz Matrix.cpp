class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            int row = matrix.size();
            if (row == 0) { return true;}
            int col = matrix[0].size();
            if (col == 0) { return true;}
            for (int i = 0; i < row; ++i) {
                int element = matrix[i][0];
                for (int j = 1; j < col && i + j < row; ++j) {
                    if (element != matrix[i + j][j] ) {
                        return false;
                    }
                }
            }
            for(int i = 1; i < col; ++i) {
                int element = matrix[0][i];
                for (int j = 1; j < row && i + j < col; ++j) {
                    if (element != matrix[j][i + j]) {
                        return false;
                    }
                }
            }
            return true;
        }
    };