// 经典拓扑，往下推答案的时候更新下个节点需要用的时间的最大值就行

#include<vector>
#include<limits.h>
using namespace std;

#define MAIN_MAX 50001

class Solution {
public:
    int queue[MAIN_MAX];
    int indegree[MAIN_MAX];
    int costTime[MAIN_MAX];
    int h, t;
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        h = t = 0;

        for (int i = 1; i < time.size() + 1; ++i) {
            indegree[i] = 0;
            costTime[i] = 0;
        }

        for (auto& rel: relations) {
            graph[rel[0]].push_back(rel[1]);
            indegree[rel[1]]++;
        }

        for (int i = 1; i < time.size() + 1; ++i) {
            if (!indegree[i]) queue[t++] = i;
        }

        int ans = 0;
        while(h < t) {
            int i = queue[h++];
            costTime[i] += time[i - 1];
            for (auto& j: graph[i]) {
                costTime[j] = max(costTime[j], costTime[i]);
                --indegree[j];
                if (!indegree[j]) queue[t++] = j;
            }
            ans = max(ans, costTime[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> relations{{1,3},{2,3}};
    vector<int> time{3,2,5};
    int ans = sol.minimumTime(n, relations, time);
    return 0;
}