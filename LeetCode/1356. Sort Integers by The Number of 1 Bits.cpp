用_popcount计算1的数量速度更快

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> result;
        vector<pair<int, int>> pArr;
        for (auto n : arr) {
            pArr.push_back({__popcount (n), n});
        }
        sort(pArr.begin(), pArr.end());
        for (auto p : pArr) {
            result.push_back(p.second);
        }
        return result;
    }
};