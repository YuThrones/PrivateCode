// 这道题的分析非常难，自己是根本想不出来，最后虽然说是拓扑排序，但是前面的分析基本想不到，只能说练coding了
// 首先要分析出来的第一点是，一个合法的输入，能够坐下的，最后必然有环在里面，无论分多少不分
// 然后要针对环的大小进行讨论，有两种情况
// 如果是环的大小大于2的大环，那么只能存在一个，也就是说找到一个比2大的最大的环就是答案
// 其次是环等于2的小环，这种情况下这个环加上他们最长的拓展链是可以与其他小环并存的，需要数量加起来
// 最后两种类型的环得出的答案中较大那个就是答案
// 上面的结论分析很难想到，一切的推理起点只有一个条件：只有感兴趣的人在自己才能在
// 这一点决定了小环的特殊性质，因为环中两人相邻直接满足了双方条件，因此外延只依赖他们，不存在其他依赖问题
// 大环倒是非常容易理解，只有围一圈才能满足答案

#include<vector>
using namespace std;

#define MAIN_MAX 100001

class Solution {
public:
    int queue[MAIN_MAX];
    int depth[MAIN_MAX];
    int indegree[MAIN_MAX];
    int h, t;
    int maximumInvitations(vector<int>& favorite) {
        h = t = 0;
        for (int i = 0; i < favorite.size(); ++i) {
            depth[i] = 0;
            indegree[i] = 0;
        }

        for (int i = 0; i < favorite.size(); ++i) {
            ++indegree[favorite[i]];
        }

        for (int i = 0; i < favorite.size(); ++i) {
            if (!indegree[i]) queue[t++] = i;
        }

        // 经过这轮处理，只剩下环的入度不为0
        while(h < t) {
            int i = queue[h++];
            depth[favorite[i]] = max(depth[favorite[i]], 1 + depth[i]);
            --indegree[favorite[i]];
            if (!indegree[favorite[i]]) queue[t++] = favorite[i];
        }


        int smallRingSum = 0;
        int bigRingNum = 0;
        int maxSize;
        for (int i = 0; i < favorite.size(); ++i) {
            if (indegree[i] != 1) continue;

            maxSize = 1;
            --indegree[i];
            for (int j = favorite[i]; j != i; j = favorite[j]) {
                --indegree[j];
                ++maxSize;
            }

            // 这里要分类讨论
            if (maxSize == 2) {
                // ，如果是长度为2的小环为中心，则他们的数量是可以累加的
                // 每个小环加上他的最大深度拓展链
                smallRingSum += 2 + depth[i] + depth[favorite[i]];
            }
            else {
                // 如果是大环，那么只能用环的长度作最大值比较了，不能留拓展链
                bigRingNum = max(bigRingNum, maxSize);
            }
        }
        return max(smallRingSum, bigRingNum);
    }
};


int main() {
    Solution sol;
    vector<int> favorite{2,2,1,2};
    int ans = sol.maximumInvitations(favorite);
    return 0;
}