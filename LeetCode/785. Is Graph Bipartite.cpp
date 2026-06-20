// 这题就是要求每条边都必须链接两个不同集合的点，本质等于要求不能存在奇数环，用染色的方式很容易找到答案

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> qu;
        for(int k = 0; k < n; ++k){
            if (color[k] == -1) {
                color[k] = 0;
                qu.push(k);
            }
            while(!qu.empty()) {
                int i = qu.front();
                qu.pop();
                int curColor = color[i];
                int nextColor = 1 - curColor;
                for(int j : graph[i]) {
                    if (color[j] < 0) {
                        color[j] = nextColor;
                        qu.push(j);
                    }
                    else if (color[j] != nextColor) {
                        return false;
                    }
                }
            }
        }      
        return true;
    }
};