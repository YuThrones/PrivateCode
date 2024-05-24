// 这道题很难，甚至连思路都想不到，是看了视频才知道用并查集来搞
// 思路是先把边根据两个节点中的最大值从小到大排序，然后从小到大根据边对节点进行并查集的合并
// 这个排序的作用是保证每次结算的都是当前可能的好路径的端点，因为这个顺序保证了当你结算时，
// 不会存在可能的更小的好路径，因为必然被更大的节点挡住或者已经结算过了
// 在union的时候需要结算路径，如果两个集合的最大节点的值一致，那么两个集合最大节点数量乘积就是他们中间以两个集合的节点为两个端点的好路径数量

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAIN_MAX 30001
// #define MAIN_MAX 8

class Solution {
public:
    int father[MAIN_MAX];
    int maxNum[MAIN_MAX];

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(),
            [&](vector<int>&a, vector<int>&b) {
                return max(vals[a[0]], vals[a[1]]) - max(vals[b[0]], vals[b[1]]) < 0;
                }
            );

        build(vals.size());
        int path = vals.size();
        for (int i = 0; i < edges.size(); ++i) {
            path += makeUnion(vals, edges[i][0], edges[i][1]);
        }
        return path;
    }

    void build(int n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
            maxNum[i] = 1;
        }
    }

    int find(int i) {
        if (father[i] != i) {
            father[i] = find(father[i]);
        }
        return father[i];
    }

    int makeUnion(vector<int>& vals, int a, int b) {
        // 除了合并，还需要返回这个过程产生的好路径数量
        int fa = find(a);
        int fb = find(b);
        int path = 0;
        if (fa == fb) return path;
        int va = vals[fa];
        int vb = vals[fb];
        if (va > vb) {
            father[fb] = fa;
        }
        else if (va < vb) {
            father[fa] = fb;
        }
        else {
            path = maxNum[fa] * maxNum[fb];
            maxNum[fa] += maxNum[fb];
            father[fb] = fa;
        }
        return path;
    }
};

int main() {
    Solution sol;
    vector<int> vals{1,3,2,1,3};
    vector<vector<int>> edges{{0,1},{0,2},{2,3},{2,4}};
    // {1, 3} {1, 2} {2, 1} {2, 3}
    int ans = sol.numberOfGoodPaths(vals, edges);
    return 0;
}