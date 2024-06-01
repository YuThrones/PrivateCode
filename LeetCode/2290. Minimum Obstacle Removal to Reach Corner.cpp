// 非常标准的01BFS模板题目
// grid表示的就是隔壁各自格子到当前格子的距离
// distance表示到(0, 0)坐标的距离
// 把(0, 0)加入起始双端队列，每次拿出队头结点(x, y)遍历周围，
// 如果distance[x][y]加上周围的grid的值比周围的distance小，
// 受理这条边，如果边是0就加入队头，否则加入队尾，
// 循环执行后右下角就是答案

#include<vector>
#include<deque>
#include<limits.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dir[]{-1, 0, 1, 0, -1};
        vector<vector<int>> distance;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            distance.push_back(vector<int>());
            for (int j = 0; j < m; ++j) {
                distance[i].push_back(INT_MAX);
            }
        }
        distance[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        while(!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (nx < 0 || ny < 0 || nx >=n || ny >= m) continue;

                if (distance[nx][ny] > grid[nx][ny] + distance[x][y]) {
                    if (grid[nx][y] == 0) {
                        dq.push_front({nx, ny});
                    }
                    else {
                        dq.push_back({nx, ny});
                    }
                    distance[nx][ny] = distance[x][y] + grid[nx][ny];
                }
            }
        }
        return distance[n - 1][m - 1];
    }
};

