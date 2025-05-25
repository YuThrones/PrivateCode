class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size(); 
        int bottom_up_area = m * n * 2;
        int sum_area = bottom_up_area;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int iternal_val = 0;
                if (grid[i][j] == 0)
                {
                    sum_area -= 2;
                    continue;
                }
                int shift = -1;
                while (shift <= 1)
                {
                    if (i + shift >=0 && i + shift < m)
                        iternal_val += max(grid[i][j] - grid[i + shift][j], 0);
                    else
                        iternal_val += grid[i][j];
                    if (j + shift >=0 && j + shift < n)
                        iternal_val += max(grid[i][j] - grid[i][j + shift],0);
                    else
                        iternal_val += grid[i][j];
                    shift += 2;
                }
                sum_area += iternal_val;
            }
        }
        return sum_area;
    }
};

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.size() == 0) {return 0;}
        int result = 0;
        vector<pair<int, int>> dir{
            {-1, 0}, {1, 0}, {0, 1}, {0, -1}
        };
        int r_size = grid.size();
        int c_size = grid[0].size();
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (grid[r][c] == 0) {continue;}
                // cout << "rc " << r << " " << c << " " << grid[r][c] << endl;
                for (auto d : dir) {
                    int x = r + d.first;
                    int y = c + d.second;
                    if (x >= 0 && x < c_size && y >= 0 && y < r_size) {
                        if (grid[r][c] > grid[x][y]) {
                            result += (grid[r][c] - grid[x][y]);
                        }
                        // cout << "xy " << x << " " << y << " " << grid[x][y] << " " << grid[r][c] - grid[x][y] << endl;
                    }
                    else {
                        result += grid[r][c];
                    }
                    cout << result << endl;
                }
                result += 2;
                // cout << "end " << result << endl;
            }
        }
        return result;
    }
};