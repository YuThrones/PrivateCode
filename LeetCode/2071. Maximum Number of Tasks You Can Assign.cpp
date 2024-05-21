// 这道题用了双端单调队列还有贪心和二分，确定一个粗狂的答案范围，用二分的方式选一个可能的答案，然后用ok函数验证答案是否可行
// ok函数在O(n)的复杂度内完成验证，验证的核心在于，用数值最高的num个工人处理数值最低的num个任务
// 也就是用贪心来确保每一步都是最赚的，尽可能完成给定数值
// 单调双端队列的使用实际上就是为了保证吃药的工人能够处理能处理的最大任务，因为后面工人不一定会吃药
// 如果不用单调双端队列，在原数组用浮标记录其实也是一样的

#include<vector>
#include<algorithm>
using namespace std;

#define MAIN_MAX 50001

class Solution {
public:
    int dq[MAIN_MAX];
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0, r = min(tasks.size(), workers.size());
        int m;
        while(l <= r) {
            m = l + ((r - l) >> 1);
            if (ok(tasks, workers, pills, strength, m)) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return r;
    }

    bool ok(vector<int>& tasks, vector<int>& workers, int pills, int strength, int num) {
        int h = 0, t = -1;
        int ti, wi, offset;
        int power;
        int cnt = 0;
        for (offset = 0, ti = 0; offset < num; ++offset) {
            wi = workers.size() - num + offset;

            // 没吃药的情况下工人可以处理哪些任务，放入队列
            power = workers[wi];
            while(ti < num && power >= tasks[ti]) {
                dq[++t] = tasks[ti++];
            }

            if (h <= t && power >= dq[h]) {
                // 工人有可以完成的任务，不用吃药,直接完成队列头部任务
                ++h;
            }
            else {
                // 工人没有任务可以完成，直接吃药，看看有哪些任务可以加入队列
                power += strength;
                ++cnt;
                while(ti < num && power >= tasks[ti]) {
                    dq[++t] = tasks[ti++];
                }

                if (h > t || dq[h] > power) {
                    // 工人还是没有任务可以完成，这种可能性失败了
                    return false;
                }

                // 吃了药的工人直接完成队列尾部任务，保证不亏
                --t;
            }
        }
        return cnt <= pills;
    }
};


int main() {
    Solution sol;
    vector<int> tasks {5, 4};
    vector<int> workers {0, 0, 0};
    int pills = 1;
    int strength = 5;
    int ans = sol.maxTaskAssign(tasks, workers, pills, strength);
    return 0;
}