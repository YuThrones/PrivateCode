// 原本想着记录重复值，好像没什么必要，去重之后排序就完了，想复杂了

#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        vector<int> vec(us.begin(), us.end());
        sort(vec.begin(), vec.end());
        if (vec.size() < 3) return vec[vec.size() - 1];
        return vec[vec.size() - 3];
    }

    // int thirdMax(vector<int>& nums) {
    //     priority_queue<int, vector<int>, greater<int>> pQueue;
    //     set<int> nSet;
    //     for (auto &n: nums) {
    //         if (nSet.find(n) != nSet.end()) continue;
    //         nSet.insert(n);
    //         if (pQueue.empty() || pQueue.size() < 3) {
    //             pQueue.push(n);
    //         }
    //         else if (pQueue.top() < n) {
    //             pQueue.pop();
    //             pQueue.push(n);
    //         }
    //     }
    //     if (pQueue.size() == 3) return pQueue.top();
    //     while(pQueue.size() > 1) pQueue.pop();
    //     return pQueue.top();
    // }
};


int main() {
    Solution s;
    vector<int> input({3, 2, 1});
    int ans = s.thirdMax(input);
    return 0;
}