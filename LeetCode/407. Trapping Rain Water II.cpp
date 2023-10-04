// 一开始自己的思路是用二维的雨水问题推导过来，但是没相出办法
// gpt给出的思路是用优先队列加bfs，确实可以解决问题，而且跟最快算法的速度在一个数量级
// 看了下最快算法，居然是用spfa进行松弛，而且通过自己定义大的矩阵等方式来加速，有点难以理解


#include<vector>
#include <queue>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        int rowSize = heightMap.size();
        int colSize = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue;
        vector<vector<bool>> markMap(rowSize, vector<bool>(colSize, false));
        int curHeight = 0;
        int res = 0;

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (i == 0 || j == 0 || i == rowSize - 1 || j == colSize - 1) {
                    pQueue.push({heightMap[i][j], i * colSize + j});
                    markMap[i][j] = true;
                }
            }
        }

        while(!pQueue.empty()) {
            pair<int, int> top = pQueue.top();
            pQueue.pop();
            curHeight = max(curHeight, top.first);
            int row = top.second / colSize;
            int col = top.second % colSize;
            for (auto dir: dirs) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow <= 0 || newRow >= rowSize - 1 || newCol <= 0 || newCol >= colSize - 1 || markMap[newRow][newCol]) continue;

                if (heightMap[newRow][newCol] < curHeight) res += curHeight - heightMap[newRow][newCol];

                markMap[newRow][newCol] = true;
                pQueue.push({heightMap[newRow][newCol], newRow * colSize + newCol});
            }
        }

        return res;
    }
};


class Solution {
public:
    using PII = pair<int, int>;

    constexpr static int N = 210, M = N * N;
    constexpr static int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

    int n, m;
    int d[N][N];
    
    PII q[M];
    int tt, hh;
    bool inQ[N][N];

#define push(x, y) q[tt++] = {x, y}; if (tt == M) tt = 0; inQ[x][y] = 1
#define pop   auto [x, y] = q[hh++]; if (hh == M) hh = 0; inQ[x][y] = 0

    int spfa(vector<vector<int>>& g) {
      memset(d, 0x3f, sizeof d);

      for (int i = 0; i < m; i++) {
        d[0][i] = g[0][i];
        d[n - 1][i] = g[n - 1][i];
        push(0, i);
        push(n - 1, i);
      }

      for (int i = 1; i < n - 1; i++) {
        d[i][0] = g[i][0];
        d[i][m - 1] = g[i][m - 1];
        push(i, 0);
        push(i, m - 1);
      }
      
      while (hh != tt) {
        pop;

        for (int i = 0; i < 4; i++) {
          int a = x + dx[i], b = y + dy[i];
          if (a >= 0 && a < n && b >= 0 && b < m) {
            int nxt = max(g[a][b], d[x][y]);
            if (d[a][b] > nxt) {
              d[a][b] = nxt;
              if (!inQ[a][b]) {
                push(a, b);
              }
            } 
          }
        }
      }

      int res = 0;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res += d[i][j] - g[i][j];

      return res;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
      n = heightMap.size();
      m = heightMap[0].size();
      if (n == 0 || m == 0) return 0;

      return spfa(heightMap);
    }
};


int main() {
    // vector<vector<int>> input = {
    //     {1,4,3,1,3,2},
    //     {3,2,1,3,2,4},
    //     {2,3,3,2,3,1}
    // };
    vector<vector<int>> input = {{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
    // vector<vector<int>> input = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    // vector<vector<int>> input = {{5,5,5,1},{5,1,1,5},{5,1,5,5},{5,2,5,8}};
    
    Solution s;
    int res = s.trapRainWater(input);
    return 0;
}