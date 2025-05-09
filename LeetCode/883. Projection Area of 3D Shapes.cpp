class Solution {
    public:
        int projectionArea(vector<vector<int>>& grid) {
            vector<int> xCount(51, 0);
            vector<int> yCount(51, 0);
            int zCount = 0;
            for (int x = 0; x < grid.size(); ++x) {
                for (int y = 0; y < grid[x].size(); ++y) {
                    if (grid[x][y] > 0){
                        ++zCount;
                        }
                    xCount[x] = max(xCount[x], grid[x][y]);
                    yCount[y] = max(yCount[y], grid[x][y]);
                    // cout << x << " " << y << " " <<xCount[x] << " " << yCount[y] << endl;
                }
            }
            int result = zCount;
            // cout << zCount <<endl;
            result = accumulate(xCount.begin(), xCount.end(), result);
            result = accumulate(yCount.begin(), yCount.end(), result);
            return result;
        }
    };