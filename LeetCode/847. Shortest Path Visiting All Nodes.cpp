// 自己没想到思路，问了ds的
// 核心就是这道题只能遍历用bfs，关键的只有两个数据，当前状态还有访问情况
// 第一个位置用u记录当前位置节点编号
// 第二个位置用v记录当前所有节点是否访问过
// 因为题目里面n < 12，所以用一个int的mask记录就行
// 然后把所有节点初始状态 {i, 1 << i} 放到队列里面
// 整个队列跑一轮步数+1，直到找到最终答案
// 本质上思路就是穷举，只是BFS剪枝
// 应该一开始先从暴力解开始想的

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int val = graph[0].size();
        int n = graph.size();
        queue<pair<int, long long>> que;
        vector<unordered_set<long long>> visited(n, unordered_set<long long>());
        int req = 0;
        for(int i = 0; i < n; ++i) {
            int mask = getMask(i);
            que.push({i, mask});
            visited[i].insert(mask);
            req |= (mask);
        }
        int ans = 0;
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; ++i) {
                pair<int, int> front = que.front();
                que.pop();
                if (front.second == req) {
                    return ans;
                }
                for(int next : graph[front.first]) {
                    long long nextMask = front.second | (getMask(next));
                    if (visited[next].contains(nextMask)) {
                        continue;
                    }
                    visited[next].insert(nextMask);
                    que.push({next, nextMask});
                }
            }
            ++ans;
        }
        return ans;
    }

    int getMask(int i) {
        return 1 << i;
    }
};

// 思路一样的，但是把数据结构改成了访问更快的vector而不是unordered_set，因为是稠密数组
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == target)
                    return steps;

                for (int next : graph[node]) {
                    int newMask = mask | (1 << next);

                    if (!visited[next][newMask]) {
                        visited[next][newMask] = true;
                        q.push({next, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};