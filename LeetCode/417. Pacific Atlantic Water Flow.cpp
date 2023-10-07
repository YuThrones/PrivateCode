// 思路就是先分别按两个边缘先各自染色，然后用深度优先遍历或者宽度优先遍历搜索把更高的高度染色，遍历染色结束之后两个颜色都有的格子就是答案
// 我是按照广度优先处理，最佳答案是深度优先，应该是因为广度优先维护队列的问题，但是也在一个数量级上

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, int &m, int &n, vector<vector<int>> &ocean, int pr, int pc){
        int DIR[][2] = { {0,-1}, {1, 0}, {0, 1}, {-1, 0} };
        for(int i =0; i<4 ; i++){
            int nr = r + DIR[i][0];
            int nc = c + DIR[i][1];
        if(nr<0 || nc<0 || nr>=m || nc>=n|| ocean[nr][nc]==1) 
        continue;

        if(heights[nr][nc]>= heights[r][c]) 
        {
        ocean[nr][nc]=1;
        dfs(heights, nr, nc, m, n, ocean, r, c);
        // dfs(heights, r-1, c, m, n, ocean, r, c);
        // dfs(heights, r, c+1, m, n, ocean, r, c);
        // dfs(heights, r, c-1, m, n, ocean, r, c);
        }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n,-1));
        vector<vector<int>> atlantic(m, vector<int>(n,-1));

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(i == 0 || j==0) pacific[i][j] =1;
                if(i == m-1 || j == n-1) atlantic[i][j]=1;
            }
        }
        
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(pacific[i][j]==1) dfs(heights, i, j, m, n, pacific, i, j);
                if(atlantic[i][j]==1) dfs(heights, i, j, m, n, atlantic, i, j);
            }
        }

        vector<vector<int>> res;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) res.push_back({i,j});
            }
        }
        return res;
    }
};

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rowSize = heights.size();
        if (!rowSize) return res;
        int colSize = heights[0].size();
        if (!colSize) return res;
        vector<vector<bool>> v1(rowSize, vector<bool>(colSize, false));
        vector<vector<bool>> v2(rowSize, vector<bool>(colSize, false));

        queue<vector<int>> q1;
        queue<vector<int>> q2;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (!v1[i][j] && (i == 0 || j == 0)) {
                    v1[i][j] = true;
                    q1.push({i, j});
                }
                
                if (!v2[i][j] && (i == rowSize - 1 || j == colSize - 1)) {
                    v2[i][j] = true;
                    q2.push({i, j});
                }
            }
        }

        while(!q1.empty()) {
            vector<int> pos = q1.front();
            q1.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int x = pos[0] + dirX[dir];
                int y = pos[1] + dirY[dir];
                if (x < 0 || y < 0 || x >= rowSize || y >= colSize) continue;
                if (heights[x][y] < heights[pos[0]][pos[1]]) continue;
                if (v1[x][y]) continue;
                v1[x][y] = true;
                q1.push({x, y});
            }
        }

        while(!q2.empty()) {
            vector<int> pos = q2.front();
            q2.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int x = pos[0] + dirX[dir];
                int y = pos[1] + dirY[dir];
                if (x < 0 || y < 0 || x >= rowSize || y >= colSize) continue;
                if (heights[x][y] < heights[pos[0]][pos[1]]) continue;
                if (v2[x][y]) continue;
                v2[x][y] = true;
                q2.push({x, y});
            }
        }

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (v1[i][j] && v2[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> input {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = s.pacificAtlantic(input);
    return 0;
}