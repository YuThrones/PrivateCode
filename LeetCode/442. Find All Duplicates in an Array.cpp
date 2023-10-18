class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(n + 1);
        vector<int> res;
        for (auto& num: nums) {
            ++record[num];
        }
        for (int i = 1; i <= n; ++i) {
            if (record[i] > 1) res.push_back(i);
        }
        return res;
    }
};