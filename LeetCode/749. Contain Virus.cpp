// 这道题理解错题意了，还以为只需要把病毒都隔离就行了，忽略了动态夸张
// 不过其实也就加个循环，每一轮dfs进行一次重新判定，ds给的答案的亮点是dfs一轮把墙的数量，威胁位置等都收集完了
// 常数时间更快

class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    int containVirus(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;  // 累计建的墙数

        while (true) {
            // vis 标记当前这一轮 DFS 访问过的感染格
            vector<vector<bool>> vis(m, vector<bool>(n, false));

            // regions[i]：第 i 个感染连通块的所有格子坐标
            vector<vector<pair<int,int>>> regions;

            // threats[i]：第 i 个感染连通块威胁到的不同空格，用 r*n+c 编码
            vector<unordered_set<int>> threats;

            // walls[i]：第 i 个感染连通块需要建的墙数（相邻空格的边数）
            vector<int> walls;

            // 1. 找出当前所有感染连通块
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !vis[i][j]) {
                        regions.push_back({});      // 新建一个连通块
                        threats.push_back({});      // 新建威胁集合
                        walls.push_back(0);         // 新建墙数计数

                        // DFS 收集该连通块的信息
                        dfs(grid, vis, i, j, regions.back(), threats.back(), walls.back());
                    }
                }
            }

            // 没有任何感染连通块了，结束
            if (regions.empty()) break;

            // 2. 找威胁最大的连通块（威胁空格数最多）
            int best = 0;
            for (int i = 1; i < regions.size(); ++i) {
                if (threats[i].size() > threats[best].size()) {
                    best = i;
                }
            }

            // 如果威胁最大的连通块都没有威胁空格，说明所有连通块都无法再传播，结束
            if (threats[best].empty()) break;

            // 3. 隔离威胁最大的连通块，累加它需要的墙数
            ans += walls[best];

            // 把该连通块的所有格子标记为已隔离 -1
            for (auto& p : regions[best]) {
                grid[p.first][p.second] = -1;
            }

            // 4. 其他感染连通块继续传播，把它们威胁到的空格变成感染 1
            for (int i = 0; i < regions.size(); ++i) {
                if (i == best) continue;  // 被隔离的那个不传播
                for (int code : threats[i]) {
                    int r = code / n;
                    int c = code % n;
                    // 如果这个空格还没被感染（也没被隔离），就感染它
                    if (grid[r][c] == 0) {
                        grid[r][c] = 1;
                    }
                }
            }

            // 进入下一天，继续循环
        }

        return ans;
    }

    // DFS 遍历一个感染连通块
    // region：当前连通块的所有格子
    // threat：当前连通块威胁到的不同空格（用 r*n+c 编码）
    // walls：当前连通块需要建的墙数（相邻空格的边数）
    void dfs(vector<vector<int>>& grid,
             vector<vector<bool>>& vis,
             int r, int c,
             vector<pair<int,int>>& region,
             unordered_set<int>& threat,
             int& walls) {

        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (grid[r][c] != 1 || vis[r][c]) return;

        vis[r][c] = true;
        region.push_back({r, c});

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

            if (grid[nr][nc] == 0) {
                // 相邻是空格：需要建一面墙，并且这个空格受到威胁
                ++walls;  // 注意：同一个空格与多个感染格相邻会多次计数，表示多面墙
                threat.insert(nr * n + nc);  // 用 set 去重，威胁大小按不同空格算
            } else if (grid[nr][nc] == 1 && !vis[nr][nc]) {
                // 相邻是未访问的感染格：继续 DFS
                dfs(grid, vis, nr, nc, region, threat, walls);
            }
            // 如果相邻是 -1（已隔离），忽略
        }
    }
};