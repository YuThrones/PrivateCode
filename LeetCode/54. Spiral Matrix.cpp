// 这道题麻烦的主要是细节，要想清楚边界条件，思路很简单，复杂度也是一定的

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans = vector<int>();
        int row_size = matrix.size();
        if (row_size == 0) {
            return ans;
        }
        int col_size = matrix[0].size();
        int row = 0;
        int col = 0;
        int row_min = -1;
        int row_max = row_size;
        int col_min = -1;
        int col_max = col_size;
        int dir[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
        };
        int dir_index = 0;
        while(row > row_min && row < row_max && col > col_min && col < col_max) {
            ans.push_back(matrix[row][col]);
            if (row + dir[dir_index][0] <= row_min) {
                col_min += 1;
                dir_index = (dir_index + 1) % 4;
            }
            else if (row + dir[dir_index][0] >= row_max) {
                col_max -= 1;
                dir_index = (dir_index + 1) % 4;
            }
            else if (col + dir[dir_index][1] <= col_min) {
                row_max -= 1;
                dir_index = (dir_index + 1) % 4;
            }
            else if (col + dir[dir_index][1] >= col_max) {
                row_min += 1;
                dir_index = (dir_index + 1) % 4;
            }

            row = row + dir[dir_index][0];
            col = col + dir[dir_index][1];
        }

        return ans;
    }
};