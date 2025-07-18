struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }

};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (int i = 0; i < mat.size(); ++i) {
            int num = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                num += mat[i][j];
            }
            pq.push({num, i});
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};