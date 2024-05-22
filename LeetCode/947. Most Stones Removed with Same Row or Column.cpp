// 经典并查集，需要知道的一个结论是行列有重复的加入同一个并查集，最后一定会消到只剩下一个
// 根据这个结论可以知道并查集最终数量就是剩余石头数量，减一下就可以知道答案

#include<vector>
#include<unordered_map>
using namespace std;

#define MAIN_MAX 1001

class Solution {
public:
    int parent[MAIN_MAX];
    unordered_map<int, int> firstRow;
    unordered_map<int, int> firstCol;

    int removeStones(vector<vector<int>>& stones) {
        build(stones.size());
        int r, c;
        for (int i = 0; i < stones.size(); ++i) {
            r = stones[i][0];
            c = stones[i][1];
            if (firstRow.find(r) == firstRow.end()) {
                firstRow[r] = i;
            }
            else {
                makeUnion(i, firstRow[r]);
            }

            if (firstCol.find(c) == firstCol.end()) {
                firstCol[c] = i;
            }
            else {
                makeUnion(i, firstCol[c]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < stones.size(); ++i) {
            if (parent[i] == i) ++cnt;
        }
        return stones.size() - cnt;
    }

    void build(int n) {
        firstRow.clear();
        firstCol.clear();
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (parent[n] != n) {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    void makeUnion(int x, int y) {
        if (find(x) != find(y)) {
            parent[find(x)] = find(y);
        }
    }
};


int main() {
    return 0;
}