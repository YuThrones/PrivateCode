// 01BFS，注意按照方向计算代价就行

#include<vector>
#include<memory.h>
#include<deque>
#include<iostream>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dir[][2]{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int distance[m][n];
        memset(distance, 0x3f, sizeof(distance));
        distance[0][0] = 0;
        
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        while(!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();
            for (int i = 1; i < 5; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int dis = (i == grid[x][y]) ? 0 : 1;
                if (distance[nx][ny] <= distance[x][y] + dis) continue;
                distance[nx][ny] = distance[x][y] + dis;
                if (dis == 0) {
                    dq.push_front({nx, ny});
                }
                else {
                    dq.push_back({nx, ny});
                }
            }
        }
        return distance[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid{{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    int ans = sol.minCost(grid);
    return 0;
}