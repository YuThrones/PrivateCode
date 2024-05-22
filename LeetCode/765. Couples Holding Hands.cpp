// 直接想可能觉得很难，但是实际上是一道很适合用并查集的题目，用数值/2作为自己的情侣编号，
// 然后把奇偶位置的加到一个集合，同一个集合中的交换数量等于集合中情侣对数-1，也就是统计每个集合的对数数量就行（关键就是这一步的思维）
// 进一步优化就是可以根据所有情侣对数和集合数量，直接用情侣对数减去集合数量就是答案
// 因为如果不需要交换，那么情侣对数等于集合数量，每多一个需要交换，就意味着会导致集合减少一个，集合中对数增加一个

#include<vector>
using namespace std;

#define MAIN_MAX 31

class Solution {
public:
    int father[MAIN_MAX];

    int minSwapsCouples(vector<int>& row) {
        build(row.size() / 2);
        for (int i = 0; i < row.size(); i += 2) {
            makeUnion(row[i] / 2, row[i + 1] / 2);
        }
        int num = 0;
        for (int i = 0; i < row.size() / 2; ++i) {
            if (father[i] == i) ++num;
        }
        return row.size() / 2 - num;
    }

    void build(int n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int i) {
        if (father[i] != i) {
            father[i] = find(father[i]);
        }
        return father[i];
    }

    void makeUnion(int x, int y) {
        if (find(x) != find(y)) {
            father[find(x)] = father[find(y)];
        }
    }
};


int main() {
    return 0;
}