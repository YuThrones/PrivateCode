// 经典字典可以解决，然后通过维护一个长度为k的最小堆二次筛选来减少数据量，最后按照规范调整下输出
// 最快的答案思路是一样的，一些实现细节上有些许优化
struct cmp{
    bool operator()(pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m = map<string, int>();
        vector<string> res =  vector<string>();
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] += 1;
        }
        priority_queue<pair<string, int>, vector<pair<string, int> >, cmp > pq = priority_queue<pair<string, int>, vector<pair<string, int> >, cmp >();
        for (auto it: m) {
            // cout << "check " << it.first << " " << it.second << endl;
            if (pq.size() < k) {
                // cout << "push 1" << endl;
                pq.push(make_pair(it.first, it.second));
            }
            else if (pq.top().second < it.second) {
                // cout << "push 2" << endl;
                pq.pop();
                pq.push(make_pair(it.first, it.second));
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};