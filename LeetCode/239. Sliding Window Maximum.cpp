// 想到的办法就是使用大根堆来维护目前k位的最大值，如果top的位置在当前k位前面，直接pop
// 最快方法是使用一个deque，左边保留目前最左边的数，右边保留大于等于当前位置的数，事实上这就是一个递减队列

#include<vector>
#include<stack>
#include<climits>
#include<queue>

using namespace std;
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second < b.second) return true;
        if (a.second > b.second) return false;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {

            while(!pq.empty() && pq.top().first <= i - k) pq.pop();
            
            pq.push(make_pair(i, nums[i]));
            if (i >= k - 1) res.push_back(pq.top().second);
        }
        
        return res;
    }
};



int main() {
    // vector<int> input{1,3,-1,-3,5,3,6,7};
    // vector<int> input{1,3,1,2,0,5};
    vector<int> input{1, -1};
    Solution s;
    // s.maxSlidingWindow(input, 3);
    s.maxSlidingWindow(input, 1);
}