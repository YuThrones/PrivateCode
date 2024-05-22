// 这道题比较容易想到用并查集，但是具体怎么处理其实有点难
// 首先要排序，同一个时刻的会议要一次性处理完
// 其次是在同一个时刻开会的人用并查集合并，合并完之后需要注意如果整个时刻处理完了某个专家的根节点并不知道秘密，要把他还原，也就是根节点设置为自己
// 这样就可以避免对后续流程的影响

#include <vector>
#include <algorithm>
using namespace std;

#define MAIN_MAX 100001

class Solution {
public:
    int father[MAIN_MAX];
    bool secret[MAIN_MAX];

    void build(int num, int first) {
        for (int i = 0; i < num; ++i) {
            father[i] = i;
            secret[i] = false;
        }
        secret[0] = true;
        secret[first] = true;
        father[first] = 0;
    }

    int find(int n) {
        if (father[n] != n) {
            father[n] = find(father[n]);
        }
        return father[n];
    }

    void makeUnion(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            secret[fy] |= secret[fx];
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        build(n, firstPerson);
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b){return a[2] < b[2];});
        int l = 0, r = 0;
        int root;
        while(l < meetings.size()) {
            r = l;
            while(r + 1 < meetings.size() && meetings[r + 1][2] == meetings[r][2]) {
                ++r;
            }

            // l到r区间内的会议都是同时的，先找并查集
            for (int i = l; i <= r; ++i) {
                makeUnion(meetings[i][0], meetings[i][1]);
            }

            // 看看并完之后根是不是知道秘密的，如果不是就清出去
            for (int i = l; i <= r; ++i) {
                root = find(meetings[i][0]);
                if (!secret[root]) {
                    father[meetings[i][0]] = meetings[i][0];
                    father[meetings[i][1]] = meetings[i][1];
                }
            }

            l = r + 1;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (secret[find(i)]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> meetings {{1,2,5},{2,3,8},{1,5,10}};
    int firstPerson = 1;
    Solution sol;
    vector<int> ans = sol.findAllPeople(n, meetings, firstPerson);
    return 0;
}