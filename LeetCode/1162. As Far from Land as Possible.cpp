// 使用bfs解决，只需要从陆地开始扩，周围一圈全部+1，直到所有为止都访问过
// 数字最大的-1就是海洋到陆地距离最大的值

#include<vector>
using namespace std;

#define MAIN_MAX 10001

static const int dir[]{-1, 0, 1, 0, -1};


class Solution {
public:
    pair<int, int> queue[MAIN_MAX];
    int visited[MAIN_MAX];
    int h, t;
    int n;

    inline int getIndex(int i, int j) {
        return i * n + j;
    }

    int maxDistance(vector<vector<int>>& grid) {
        h = t = 0;
        n = grid.size();
        int index;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                index = getIndex(i, j);
                if (grid[i][j] == 1) {
                    queue[t++] = make_pair(i, j);
                    visited[index] = true;
                }
                else {
                    visited[index] = false;
                }
            }
        }
        int ans = 0;

        int len;
        while(h < t) {
            len = t - h;
            while(len-- > 0) {
                int i = queue[h].first, j = queue[h].second;
                ++h;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dir[k], y = j + dir[k + 1];
                    index = getIndex(x, y);
                    if (x >= 0 && x < n && y >= 0 && y < n && !visited[index]) {
                        visited[index] = true;
                        queue[t++] = make_pair(x, y);
                        grid[x][y] = grid[i][j] + 1;
                        ans = max(ans, grid[x][y]);
                    }
                }
            }
        }

        return ans - 1;
    }
};


int main() {
    return 0;
}