// 这道题可以按拓扑排序的思路做，先是把所有位置开头的长度为stamp长度的位置都遍历一下
// 统计下已经正确的位置的数量，作为图的入度，并且把错误位置指向开始位置，这样当被盖章修正后可以索引减少开头位置的入度
// 然后用一个队列维持入度为0的开头位置，遍历他们并且把还没有访问的位置对应的开头位置入度减少，当为0时入列
// 处理完队列后把依次出列的头部逆序就是答案，复杂度是O(m * n)，m为stamp长度，n位target长度

// 最快方法是一个双指针加栈的做法，光看代码有点难理解，核心思路大概类似于先比较
// 比较成功了就是可行的后置位置，不行就往前回退找个起始位置一致的地方盖章，盖完再对比下行不行，可以就是可行位置


#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// #define MAIN_MAX 1001

// class Solution {
// public:
//     vector<int> graph[MAIN_MAX];
//     bool visited[MAIN_MAX];
//     int queue[MAIN_MAX];
//     int h, t;
//     int indegree[MAIN_MAX];
//     int sLen;
//     int tLen;

//     vector<int> movesToStamp(string stamp, string target) {
//         tLen = target.length();
//         sLen = stamp.length();
//         for (int i = 0; i < target.length(); ++i) {
//             visited[i] = false;
//             graph[i].clear();
//             indegree[i] = sLen;
//         }
//         h = t = 0;

//         for (int i = 0; i < tLen - sLen + 1; ++i) {
//             for (int j = 0; j < sLen; ++j) {
//                 if (target[i + j] == stamp[j]) {
//                     --indegree[i];
//                 }
//                 else {
//                     // 有一个错误位置 i + j，说明这个错误位置被修正的时候会导致i为开头的入度-1
//                     graph[i + j].push_back(i);
//                 }
//             }
//             if (indegree[i] == 0) {
//                 queue[t++] = i;
//             }
//         }

//         vector<int> ans;
//         while(h < t) {
//             for (int i = 0; i < sLen; ++i) {
//                 int j = queue[h] + i;
//                 if (!visited[j]) {
//                     visited[j] = true;
//                     for (auto& l: graph[j]) {
//                         --indegree[l];
//                         if (indegree[l] == 0) {
//                             queue[t++] = l;
//                         }
//                     }
//                 }
//             }
//             ans.push_back(queue[h++]);
//         }

//         if (ans.size() < tLen - sLen + 1) {
//             return vector<int>();
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        vector<int> st;
        int szt = target.size();
        int szsp = stamp.size();
        for (int idx = 0; idx < target.size();) {
            int i = idx, p = 0;

            // 从一个开头遍历位置，看看中间有没有不一样的
            for (; i < szt, p < szsp; p++) {

                // 一样的话两边索引都往下走就行，不用处理
                if (target[i] == stamp[p]) {
                    i++;
                    continue;
                }

                // 如果是第一个位置就不一样了可以不管，最后往i位置一盖就完事了
                if (i == idx)
                    continue;


                // 非首位不一样，需要往回找个位置盖一下能让当前位置一致的
                int backward = -1;
                while (backward++ < p && i-backward >= idx) {
                    if (backward == p) {
                        // 完全回退了整个邮戳长度，没法再退了，如果这时候没有收集一些可行的盖戳位置，说明无解，可以直接返回了
                        if (!st.size()) {
                            break;
                        }

                        // st.back是之前尝试的临时回退盖戳位置，说明这位置不行，不能盖戳，把他回退下再看看有没有可能再往前找个邮戳位置
                        i -= backward;
                        backward = 0;
                        p = i - st.back();
                        st.pop_back();
                        continue;
                    }
                    if (target[i-backward] == stamp[0]) {
                        // 前面有个可以作为开头的位置，先盖上，然后再看看当前情况行不行
                        if (i-p < 0) return {};
                        st.push_back(i-p);
                        i -= backward;
                        p = -1;
                        break;
                    }
                }
                if (!st.size()) {
                    p -= i - idx;
                    i = idx;
                }
            }
            if (i-p < 0 || (p == szsp && i == idx)) return {};
            // 一个位置对比完完全一致，说明这个开头是可以作为后续盖的放进去的
            res.push_back(i-p);

            // 在完全一致的盖戳位置之前有一些可能可以被他修正的位置倒进去
            for (auto p = st.rbegin(); p != st.rend(); p++) res.push_back(*p);
            st.clear();
            idx = i;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




int main() {
    Solution sol;
    // string stamp = "mfasqahtqo", target = "mfasqahtqo";
    string stamp = "abc", target = "abcabc";
    vector<int> ans = sol.movesToStamp(stamp, target);
    return 0;
}
