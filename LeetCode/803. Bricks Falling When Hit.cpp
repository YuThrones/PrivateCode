// 这道题有点天马行空了，不仅仅是用洪泛算法，还用了时光倒流的处理技巧
// 核心的思路是用数字表示砖块被轰击后的结果，1表示还有砖块，0表示空的或者被轰炸之后空了，-1表示打了空气或者被轰炸了多次
// 在用轰炸位置处理一次之后，把跟天花板连接的部分标记为2，然后开始逆处理，从最后一颗炮弹开始依次把数字加回去，
// 这样处理之后如果位置变成了1，说明这次轰炸正式砖块消失原因，这时候看看自己是不是天花板，或者四周有没有2，有2代表这个位置是连接着天花板的，
// 如果这这样，进行洪泛标记，这次所有把1变成2的数量也就是这次轰炸导致的砖块掉落数量
// 非常巧妙，但是没学过正常很难想到，只能说当coding练习了。


#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int n, m;

    // 遇到1就改成2，返回改变的数量
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1) return 0;
        grid[x][y] = 2;
        int ans = 1;
        ans += dfs(grid, x - 1, y);
        ans += dfs(grid, x + 1, y);
        ans += dfs(grid, x, y - 1);
        ans += dfs(grid, x, y + 1);
        return ans;
    }

    bool ok(vector<vector<int>>& grid, int x, int y) {
        return grid[x][y] == 1 && 
            ((x == 0)
            || (x > 0 && grid[x - 1][y] == 2)
            || (x < n - 1 && grid[x + 1][y] == 2)
            || (y > 0 && grid[x][y - 1] == 2)
            || (y < m - 1 && grid[x][y + 1] == 2));
    }


    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size();
        vector<int> ans;
        if (n < 2) return ans;
        m = grid[0].size();

        // 把炮弹轰炸的位置都-1，后面用时光倒流的方式做
        for (int i = 0; i < hits.size(); ++i) {
            int x = hits[i][0];
            int y = hits[i][1];
            grid[x][y] -= 1;
        }

        // 把天花板所有1都染成2,
        for (int i = 0; i < m; ++i) {
            dfs(grid, 0, i);
        }

        // 逆转轰炸过程，当一个位置从0变成1，检查左右和上方是否有2，或者自己是天花板，这种情况说明他导致了后面的掉落，需要染色统计
        for (int i = hits.size() - 1; i >= 0; --i) {
            int x = hits[i][0];
            int y = hits[i][1];
            grid[x][y] += 1;

            if (ok(grid, x, y)) {
                ans.push_back(dfs(grid, x, y) - 1);
            }
            else {
                ans.push_back(0);
            }
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }

};

int main() {
    Solution sol;
    vector<vector<int>> grid{};
    vector<vector<int>> hits{};
    sol.hitBricks(grid, hits);
    return 0;
}