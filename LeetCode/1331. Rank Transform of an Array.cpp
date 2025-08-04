class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> set;
        for (auto n : arr) {
            if (set.find(n) == set.end()) {
                set.insert(n);
                pq.push(n);
            }
        }
        unordered_map<int, int> rank;
        int r = 1;
        while(!pq.empty()) {
            rank[pq.top()] = r;
            pq.pop();
            ++r;
        }
        for (auto n : arr) {
            res.push_back(rank[n]);
        }
        return res;
    }
};