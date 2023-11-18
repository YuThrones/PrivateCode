// 也是一个排序就能解决的问题，注意下不足3个的情况别越界就行
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n, "x");
        if (!n) return res;
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({score[i], i});
        }
        sort(vec.begin(), vec.end());
        res[vec[n - 1].second] = "Gold Medal";
        if (n < 2) return res;
        res[vec[n - 2].second] = "Silver Medal";
        if (n < 3) return res;
        res[vec[n - 3].second] = "Bronze Medal";
        for (int i = 0; i < n - 3; ++i) {
            res[vec[i].second] = to_string(n - i);
        }
        return res;
    }
};