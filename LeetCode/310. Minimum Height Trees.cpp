// 自己写了一下，虽然算法是对的，但是时间复杂度明显达不到，这题我的思路是每个节点尝试作为根节点，然后作深搜，记忆化存储，大方向没错，但是优化的有问题
// 看了下最佳答案，他的做法是先选一个节点做一次深搜，然后在这个节点的基础上，通过记录这个节点的最高子树和次高子树，保证了可以利用原本的搜索答案来进行新根节点的计算

const int N = 2e4 + 1;
class Solution {
public: 
    int e[N << 1], pre[N << 1], h[N], cnt = 0;
    void add(int u, int v) {
        e[cnt] = v; pre[cnt] = h[u]; h[u] = cnt++;
    } 
    int dep[N];
    int dfs(int x, int fa) {
        for (int i = h[x]; i != -1; i = pre[i]) {
            int y = e[i];
            if (y == fa) continue;
            dep[x] = max(dep[x], dfs(y, x) + 1);
        }
        // cout << x << ":" << dep[x] << endl;
        return dep[x];
    }
    int f[N];
    void dfs(int x, int fa, int la) {
        f[x] = max(la, dep[x]);
        int fir = la, sec = 0;
        for (int i = h[x]; ~i; i = pre[i]) {
            if (e[i] == fa) continue;
            if (dep[e[i]] + 1 >= fir) sec = fir, fir = dep[e[i]] + 1;
            else if (dep[e[i]] + 1 > sec) sec = dep[e[i]] + 1;
        }

        for (int i = h[x]; ~i; i = pre[i]) {
            if (e[i] == fa) continue;
            if (dep[e[i]] + 1 == fir) dfs(e[i], x, sec + 1);
            else dfs(e[i], x, fir + 1);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for (int i = 0; i < edges.size(); i++) 
            add(edges[i][0], edges[i][1]), add(edges[i][1], edges[i][0]);
        
        dfs(0, 0);
        dfs(0, 0, 0);
        int mindep = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) mindep = min(mindep, f[i]);
        vector<int> res;
        for (int i = 0; i < n; i++) if (f[i] == mindep) res.push_back(i);
        return res; 
    }
};