// 图最短路径的变种，距离不是累加而是取过程最大值，其他没区别
// 最快答案把二维数组转一维，其他思路一样

#include<vector>
#include<memory.h>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dir[]{-1, 0, 1, 0, -1};
        int row = heights.size();
        int col = heights[0].size();
        int distance[row][col];
        bool visited[row][col];
        memset(distance, 0x3f, sizeof(distance));
        memset(visited, false, sizeof(visited));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        distance[0][0] = 0;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            vector<int> head = pq.top();
            pq.pop();
            int v = head[0];
            int r = head[1];
            int c = head[2];

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == row - 1 && c == col - 1) {
                return distance[row - 1][col - 1];
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if (nr < 0 || nc < 0 || nr >= row || nc >= col) continue;

                int diff = max(abs(heights[r][c] - heights[nr][nc]), distance[r][c]);

                if (diff < distance[nr][nc]) {
                    pq.push({diff, nr, nc});
                    distance[nr][nc] = diff;
                }
            }
        }

        return distance[row - 1][col - 1];
    }
};