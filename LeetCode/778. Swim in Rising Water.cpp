// 可以用并查集做，也可以用Dijkstra算法搞定，这里先用Dijkstra算法练习，不过不是最快的

#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dir[]{-1, 0, 1, 0, -1};
        int row = grid.size();
        int col = grid[0].size();
        int distance[row][col];
        bool visited[row][col];
        memset(distance, 0x3f, sizeof(distance));
        memset(visited, false, sizeof(visited));

        distance[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({distance[0][0], 0, 0});
        while(!pq.empty()) {
            int d = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == row - 1 && c == col - 1) return distance[r][c];

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if (nr < 0 || nc < 0 || nr >= row || nc >= col || visited[nr][nc]) continue;

                int nd = max(distance[r][c], grid[nr][nc]);
                if (nd < distance[nr][nc]) {
                    distance[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }

        return distance[row - 1][col - 1];
    }
};