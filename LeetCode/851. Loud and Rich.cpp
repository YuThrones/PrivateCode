// 很经典的拓扑排序了，拓扑顺序遍历的过程中进行比较把更小的答案往下推就行了

#include<vector>
using namespace std;

#define MAIN_MAX 501

class Solution {
public:
    int queue[MAIN_MAX];
    int indegree[MAIN_MAX];
    int h, t;

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> graph(quiet.size());
        h = t = 0;

        vector<int> ans(quiet.size());
        for (int i = 0; i < quiet.size(); ++i) {
            indegree[i] = 0;
            ans[i] = i;
        }

        for (auto& rp: richer) {
            graph[rp[0]].push_back(rp[1]);
            ++indegree[rp[1]];
        }

        for (int i = 0; i < quiet.size(); ++i) {
            if (indegree[i] == 0) {
                queue[t++] = i;
            }
        }

        while(h < t) {
            int i = queue[h++];
            for (auto& j: graph[i]) {
                --indegree[j];
                if (quiet[ans[i]] < quiet[ans[j]]) {
                    ans[j] = ans[i];
                }
                if (indegree[j] == 0) {
                    queue[t++] = j;
                }
            }
        }

        return ans;
    }
};


int main() {

    return 0;
}