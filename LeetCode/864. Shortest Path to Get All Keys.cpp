// 这道题很有意思，把持有的钥匙数量作为额外的一个维度，跟横纵坐标一起记录状态
// 用BFS算法解，如果想到了这个想法，剩下就是coding问题了

#include<vector>
#include<string>
#include<tuple>
#include<memory.h>
using namespace std;

#define MAX_M 30
#define MAX_N 30
#define MAX_K 6 



class Solution {
public:
    // int distance[MAX_M][MAX_N][1 << MAX_K];
    bool visited[MAX_M][MAX_N][1 << MAX_K];
    tuple<int, int, int> queue[MAX_M * MAX_N * (1 << MAX_K)];
    int h, t;

    void build() {
        // memset(distance, 0x3f, sizeof(distance));
        memset(visited, false, sizeof(visited));
        h = t = 0;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int dir[]{-1, 0, 1, 0, -1};
        build();
        int m = grid.size();
        int n = grid[0].length();
        int key = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    key |= 1 << (grid[i][j] - 'a');
                }

                // 起始点
                if (grid[i][j] == '@') {
                    // distance[i][j][0] = 0;
                    queue[t++] = {i, j, 0};
                }
            }
        }

        int level = 1;
        int count = 1;
        while(h < t) {
            for (int j = 0; j < count; ++j)  {
                auto& top = queue[h++];
                int x = get<0>(top);
                int y = get<1>(top);
                int k = get<2>(top);

                if (visited[x][y][k]) continue;
                visited[x][y][k] = true;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dir[i];
                    int ny = y + dir[i + 1];
                    int nk = k;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny][nk]) continue;

                    // 墙不能通过
                    if (grid[nx][ny] == '#') continue;

                    // 有锁但是没钥匙
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z' && (nk & 1 << (grid[nx][ny] - 'A')) == 0) {
                        continue;
                    }

                    // 有钥匙，捡起来
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                        nk |= 1 << (grid[nx][ny] - 'a');
                        if (nk == key) return level;
                        
                    }
                    queue[t++] = {nx, ny, nk};
                }
            }
            count = t - h;
            ++level;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    // vector<string> grid{"@.a..","###.#","b.A.B"};
    vector<string> grid{"@..aA","..B#.","....b"};
    int ans = sol.shortestPathAllKeys(grid);
    return 0;
}