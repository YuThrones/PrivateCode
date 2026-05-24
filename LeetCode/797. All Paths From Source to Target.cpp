class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<vector<int>>& graph, int cur, int target) {
        // 到达终点，保存路径
        if (cur == target) {
            ans.push_back(path);
            return;
        }
        // 遍历所有相邻节点
        for (int next : graph[cur]) {
            path.push_back(next);
            dfs(graph, next, target);
            path.pop_back(); // 回溯
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ans.clear();
        path.clear();
        int n = graph.size();
        path.push_back(0); // 起点入路径
        dfs(graph, 0, n - 1);
        return ans;
    }
};