// 这道题比较难，需要使用洪泛算法来做，首先是每个为1的位置进行dfs，对原有的grid进行数字填充，把不同的岛屿填上不同数字
// 然后根据数字不同统计不同岛屿的大小，
// 接着就是最终的寻找空位置，尝试链接四个方向的岛屿，并且统计链接后的大小，得出答案

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int num, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
            return;
        }
        grid[x][y] = num;
        dfs(grid, num, x - 1, y);
        dfs(grid, num, x, y - 1);
        dfs(grid, num, x + 1, y);
        dfs(grid, num, x, y + 1);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int num = 2;
        int col = grid.size();
        int row = grid.size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, num, i, j);
                    ++num;
                }
            }
        }

        vector<int> island(num, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] > 1) {
                    ++island[grid[i][j]];
                }
            }
        }

        int ans = *max_element(island.begin(), island.end());

        vector<bool> visited(num, false);
        int up, down, left, right, cnt;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != 0) continue;
                up = i > 0 ? grid[i - 1][j] : 0;
                down = i < row - 1 ? grid[i + 1][j] : 0;
                left = j > 0 ? grid[i][j - 1] : 0;
                right = j < col - 1 ? grid[i][j + 1] : 0;
                cnt = 0;

                if (!visited[up]) {
                    visited[up] = true;
                    cnt += island[up];
                }

                if (!visited[down]) {
                    visited[down] = true;
                    cnt += island[down];
                }

                if (!visited[left]) {
                    visited[left] = true;
                    cnt += island[left];
                }

                if (!visited[right]) {
                    visited[right] = true;
                    cnt += island[right];
                }

                visited[up] = false;
                visited[down] = false;
                visited[left] = false;
                visited[right] = false;

                ans = max(ans, cnt + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid{{1,0},{0,1}};
    int ans = sol.largestIsland(grid);
    return 0;
}