// 这题就是属于只要点一下就很好做的那种
// 要找两个点之间路径都不大于某个值，其实可以先把边和要求从小到大排序
// 然后按照边的大小把比需求限制小的边都加入并查集，检查两个点是否是同一个集合就可以得到答案

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAIN_MAX 100001

class Solution {
public:
    int father[MAIN_MAX];

    void build(int n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int n) {
        if (father[n] != n) {
            father[n] = find(father[n]);
        }
        return father[n];
    }

    void makeUnion(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = father[fy];
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        build(n);
        vector<vector<int>> data;
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            vector<int>& q = queries[i];
            data.push_back({q[0], q[1], q[2], i});
        }
        sort(data.begin(), data.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        int j = 0;
        for (auto& q: data) {
            for (; j < edgeList.size(); ++j) {
                auto& e = edgeList[j];
                if (e[2] < q[2]) makeUnion(e[0], e[1]);
                else break;
            }
            ans[q[3]] = (find(q[0]) == find(q[1]));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> edgeList{{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    vector<vector<int>> queries{{0,1,2},{0,2,5}};
    sol.distanceLimitedPathsExist(n, edgeList, queries);
    return 0;
}