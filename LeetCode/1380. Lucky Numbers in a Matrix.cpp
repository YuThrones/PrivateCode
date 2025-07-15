class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        if (row == 0) {
            return result;
        }
        int col = matrix[0].size();
        vector<int> rowMin(row, INT_MAX);
        vector<int> colMax(col, INT_MIN);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rowMin[i] == matrix[i][j] && colMax[j] == matrix[i][j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};