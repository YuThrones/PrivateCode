// 思路不难，就是用哈希表统计出词频，然后使用固定长度的小根堆来保证只有最大的k个词频在堆中，再弹出即可
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            ++m[nums[i]];
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq = priority_queue<pair<int, int>, vector<pair<int, int> >, cmp >();
        for (auto it: m) {
            if (pq.empty()) {
                pq.push(make_pair(it.first, it.second));
            }
            else if (pq.size() < k || pq.top().second < it.second){
                pq.push(make_pair(it.first, it.second));
                if (pq.size() > k) {
                    pq.pop();
                }
            }
            cout << pq.top().first << " " << pq.top().second << endl;
        }
        vector<int> res = vector<int>();
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};