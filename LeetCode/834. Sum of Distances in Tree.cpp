// 直接统计距离超时了

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        vector<vector<int>> con(n, vector<int>());
        for(int i = 0; i < n - 1; ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            con[a].push_back(b);
            con[b].push_back(a);
        }
        queue<int> que;
        que.push(0);
        distance[0][0] = 0;
        while(!que.empty()) {
            int front = que.front();
            que.pop();
            for(int next : con[front]) {
                if (distance[next][next] == 0) {
                    continue;
                }
                que.push(next);
                distance[next][next] = 0;
                for(int i = 0; i < n; ++i) {
                    if (distance[front][i] != INT_MAX) {
                        distance[next][i] = distance[i][next] = min(distance[front][i] + 1, distance[i][next]);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            int count = 0;
            for(int j = 0; j < n; ++j) {
                if (distance[i][j] != INT_MAX) {
                    count += distance[i][j];
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// 一个换根DP算法的工程优化版本，比ds提供的要更快，不过更难看懂
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // 只有 1 个节点时，它到自己的距离和就是 0，直接返回，避免后面 adj 大小为 0 的边界情况
        if (n == 1) return {0};

        // ============================================================
        // 1. 用 CSR（Compressed Sparse Row，压缩稀疏行）/ 前向星建图
        //    目的：把 vector<vector<int>> 换成一维连续数组，
        //    只有两次大块内存分配，遍历时顺序访问，对 CPU cache 友好。
        //
        //    head 最终语义：
        //        head[u]      = 节点 u 的邻接边在 adj 中的起始下标
        //        head[u + 1]  = 节点 u 的邻接边在 adj 中的结束下标（开区间）
        //        即节点 u 的邻居是 adj[head[u] .. head[u+1]-1]
        //    此时 head 的大小为 n + 1。
        // ============================================================
        vector<int> head(n + 1, 0);

        // 1.1 统计每个节点的度数。
        //     技巧：先累加到 head[u + 1] 上，这样做完前缀和后
        //     head[u] 天然变成"节点 u 的起点偏移"，不用额外减。
        for (const auto& edge : edges) {
            head[edge[0] + 1]++;
            head[edge[1] + 1]++;
        }

        // 1.2 对 head 做前缀和，得到每个节点的起始偏移量。
        //     做完后：
        //         head[0] = 0
        //         head[u] = 节点 0..u-1 的度数之和
        //         head[n] = 所有节点的度数之和 = 2 * (n - 1)
        for (int i = 0; i < n; ++i) {
            head[i + 1] += head[i];
        }

        // 1.3 把边填进一维数组 adj。
        //     无向树有 n - 1 条边，每条边存两个方向，所以 adj 大小 = 2(n - 1)。
        vector<int> adj(n * 2 - 2);

        // current_head 是一份可写的游标副本，
        // 每往 adj 里写一个邻居，就把对应游标往后推一格。
        // 注意：head 本身保持不变，用于后面查询每个节点的区间。
        vector<int> current_head = head;
        for (const auto& edge : edges) {
            // 边 a -> b：放在 a 的邻接区间里
            adj[current_head[edge[0]]++] = edge[1];
            // 边 b -> a：放在 b 的邻接区间里
            adj[current_head[edge[1]]++] = edge[0];
        }

        // ============================================================
        // 2. 用 BFS 把树"扁平化"成一个数组 order
        //    order 的性质：父节点一定排在子节点前面（拓扑序）。
        //    因此：
        //        - 正向遍历 order（i: 0 -> n-1） 等价于前序 DFS（父 -> 子）
        //        - 反向遍历 order（i: n-1 -> 0） 等价于后序 DFS（子 -> 父）
        //    这样后面两趟 DP 只需要两个 for 循环，不需要递归、不需要 std::function。
        // ============================================================
        vector<int> order(n);       // BFS 序，最终 order[0] = 0，父在前子在后
        vector<int> parent(n, -1);  // parent[u] = u 的父节点；根的父节点为 -1

        int head_idx = 0;   // BFS 队列头指针
        int tail_idx = 0;   // BFS 队列尾指针（也即下一个空位）

        order[tail_idx++] = 0;  // 以 0 号节点为根，入队

        while (head_idx < tail_idx) {
            int u = order[head_idx++];  // 取出队首 u

            // 遍历 u 的所有邻居（在 CSR 上就是 adj 的一段连续区间）
            for (int i = head[u]; i < head[u + 1]; ++i) {
                int v = adj[i];

                // 由于树无环，只要 v 不是 u 的父节点，v 就一定是 u 的子节点，
                // 而且还没被访问过（每个非根节点只会被它的父节点发现一次）。
                if (v != parent[u]) {
                    parent[v] = u;          // 记录父节点
                    order[tail_idx++] = v;  // 子节点入队
                }
            }
        }

        // ============================================================
        // 3. 两趟迭代 DP（换根 DP）
        //    count[u] : 以 u 为根的子树大小
        //    ans[u]   : u 到其子树中所有节点的距离之和
        // ============================================================
        vector<int> count(n, 1);  // 每个节点至少包含自己，所以初始为 1
        vector<int> ans(n, 0);    // 初始为 0

        // ---------- Pass 1：反向遍历 order，从叶子到根 ----------
        // 等价于后序 DFS，保证处理 u 时它的所有子节点都已处理完。
        for (int i = n - 1; i >= 0; --i) {
            int u = order[i];

            // 遍历 u 的邻居，只处理子节点（跳过父节点）
            for (int j = head[u]; j < head[u + 1]; ++j) {
                int v = adj[j];
                if (v != parent[u]) {
                    // 注意：原代码把 [[unlikely]] 写在了语句体内部，这是无效的。
                    // 正确写法应放在 if 条件后面：if (v != parent[u]) [[likely]] { ... }
                    // 因为 u 的邻居中只有 1 个是父节点，绝大多数 v 都是子节点，
                    // 所以这个分支实际是 likely 而不是 unlikely。

                    // 子树大小相加
                    count[u] += count[v];

                    // 合并子节点 v 的贡献：
                    //   ans[v]    : v 到 v 子树内各点的距离和
                    //   count[v]  : 对 v 子树内每个点，u 到它的距离比 v 到它多 1，
                    //               总共多 count[v]
                    // 两者相加就是 v 这棵子树对 u 的贡献。
                    ans[u] += ans[v] + count[v];
                }
            }
        }
        // Pass 1 结束后：
        //   count[u] = 子树 u 的大小
        //   ans[u]   = u 到"自己子树内所有节点"的距离和
        //   特别地，ans[0] 已经是根 0 到所有节点的距离和（因为 0 的子树就是整棵树）。

        // ---------- Pass 2：正向遍历 order，从根到叶子 ----------
        // 等价于前序 DFS，保证处理 u 时它的父节点 p = parent[u] 的答案已算好。
        // 换根公式：
        //   当根从 p 移到子节点 u 时：
        //     - u 子树内共 count[u] 个点，它们到 u 的距离比到 p 少 1  => ans 减 count[u]
        //     - 其余 n - count[u] 个点，到 u 的距离比到 p 多 1        => ans 加 (n - count[u])
        //   即：ans[u] = ans[p] - count[u] + (n - count[u])
        for (int i = 1; i < n; ++i) {  // i = 0 是根，答案已在 Pass 1 算好，跳过
            int u = order[i];          // 当前节点
            int p = parent[u];         // 它的父节点
            ans[u] = ans[p] - count[u] + (n - count[u]);
        }

        // 此时 ans[u] 已是 u 到"整棵树所有节点"的距离和
        return ans;
    }
};

// ds提供的换根DP算法
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // 计算每个节点连接点
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> sz(n, 1);   // 子树大小
        vector<int> ans(n, 0);  // 每个点到所有点的距离和

        // 第一次 DFS：计算 sz 和以 0 为根时的 ans
        function<void(int, int)> dfs1 = [&](int u, int parent) {
            for (int v : g[u]) {
                // 去掉父节点才能保证不会来回统计
                if (v == parent) continue;

                // 要先跑dfs1，保证子节点的数量统计对了
                dfs1(v, u);

                sz[u] += sz[v];
                ans[u] += ans[v] + sz[v];
            }
        };

        // 跑完之后ans[0]是对的，其他还不对
        dfs1(0, -1);

        // 第二次 DFS：换根，计算所有节点的答案
        function<void(int, int)> dfs2 = [&](int u, int parent) {
            for (int v : g[u]) {
                if (v == parent) continue;

                // 根换成v了，之前v的子树的距离相对u就-1，其他节点就+1
                ans[v] = ans[u] - sz[v] + (n - sz[v]);

                dfs2(v, u);
            }
        };

        dfs2(0, -1);

        return ans;
    }
};