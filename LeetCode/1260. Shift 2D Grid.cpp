// 最佳答案是经过三次翻转，优势在于不需要额外申请空间，所以更快

// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        rotate(&grid, k);
        return grid;
    }

private:
    void rotate(vector<vector<int>> *grid, int k) {
        k %= grid->size() * (*grid)[0].size();
        reverse(grid, 0, grid->size() * (*grid)[0].size());
        reverse(grid, 0, k);
        reverse(grid, k, grid->size() * (*grid)[0].size());
    }
    
    void reverse(vector<vector<int>> *grid, int start, int end) {
        for (; start < end; ++start, --end) {
            int start_r = start / (*grid)[0].size();
            int start_c = start % (*grid)[0].size();
            int end_r = (end - 1) / (*grid)[0].size();
            int end_c = (end - 1) % (*grid)[0].size();
            swap((*grid)[start_r][start_c], (*grid)[end_r][end_c]);
        }
    }
};


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> result;
        int row = grid.size();
        int col = grid[0].size();

        for (int r = 0; r < row; ++r) {
            result.push_back(vector<int>(col, 0));
        }

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                int temp_c = (c + k) % col;
                int temp_r = (r + (c + k) / col) % row;
                result[temp_r][temp_c] = grid[r][c];
            }
        }

        // for (int r = 0; r < row; ++r) {
        //     for (int c = 0; c < col; ++c) {
        //         cout << result[r][c] << " ";
        //     }
        //     cout << endl;
        // }

        return result;
    }
};