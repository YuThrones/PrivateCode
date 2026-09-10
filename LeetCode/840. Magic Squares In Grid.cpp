class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0) {return 0;}
        int c = grid[0].size();
        int ans = 0;
        for(int x = 0; x < r; ++x) {
            for(int y = 0; y < c; ++y) {
                if(isOk(grid, r, c, x, y)) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    bool isOk(vector<vector<int>>& grid, int r, int c, int x, int y) {
        if (r - x < 3 || c - y < 3) {
            return false;
        }
        vector<int> rec(16, 0);
        for(int i = x; i < x + 3; ++i) {
            for(int j = y; j < y + 3; ++j) {
                if(grid[i][j] < 1 || grid[i][j] > 9) {
                    return false;
                }
                if(rec[grid[i][j]] > 0) {
                    return false;
                }
                rec[grid[i][j]] = 1;
            }
        }

        int sum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        for(int i = 0; i < 3; ++i) {
            if (grid[x + i][y] + grid[x + i][y + 1] + grid[x + i][y + 2] != sum) 
            {
                return false;
            }

            if (grid[x][y + i] + grid[x + 1][y + i] + grid[x + 2][y + i] != sum) 
            {
                return false;
            }
        }

        if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != sum) {
            return false;
        }

        if (grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2] != sum) {
            return false;
        }

        return true;
    }
};