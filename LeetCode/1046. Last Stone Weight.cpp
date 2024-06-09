// 一眼大根堆维护数据结构，O(nlogn)复杂度解决

#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pQueue(stones.begin(), stones.end());
        for (auto& i: stones) {
            pQueue.push(i);
        }
        while(pQueue.size() > 1) {
            int a = pQueue.top();
            pQueue.pop();
            int b = pQueue.top();
            pQueue.pop();
            if (a != b) {
                pQueue.push(a - b);
            }
        }
        if (pQueue.empty()) return 0;
        return pQueue.top();
    }
};
