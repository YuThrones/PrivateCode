// 这道题一开始想拿两个数组分组，想简单了，得用bfs把相邻点染色，而不是直接就分组，这样会遇到有可能需要翻转多个节点才能解决的情况

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> nearby(n + 1, vector<int>());
        for(auto& dis : dislikes) {
            nearby[dis[0]].push_back(dis[1]);
            nearby[dis[1]].push_back(dis[0]);
        }
        vector<int> color(n + 1, - 1);
        for(int i = 1; i <= n; ++i) {
            if(color[i] != -1) {continue;}

            queue<int> q;
            color[i] = 0;
            q.push(i);
            
            while(!q.empty()) {
                int front = q.front();
                q.pop();

                for(int near : nearby[front]) {
                    if (color[near] == -1) {
                        color[near] = 1 ^ color[front];
                        q.push(near);
                    }
                    else {
                        if (color[near] == color[front]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

// 最快答案，用并查集来处理，如果发现两个dislikes对象在同一个组就是false
// 用a + n表示这是a的敌人组的，很巧妙的做法
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(2 * n + 1);
        iota(parent.begin(), parent.end(), 0);

        for (const auto& d : dislikes) {
            int a = d[0], b = d[1];
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;
            parent[ra] = find(b + n);
            parent[rb] = find(a + n);
        }
        return true;
    }

private:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // сжатие путей (halving)
            x = parent[x];
        }
        return x;
    }
};