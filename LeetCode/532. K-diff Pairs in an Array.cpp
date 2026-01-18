class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> dct;
        for (auto n : nums) {
            dct[n] += 1;
        }
        int ans = 0;
        for (auto it : dct) {
            // cout << it.first << " " << it.second << endl;
            if (k > 0) {
                if (dct.find(it.first + k) != dct.end()) {
                    ans += 1;
                }
            }
            else {
                if (it.second > 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};