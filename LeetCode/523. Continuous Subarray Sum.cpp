class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> record(nums.size(), 0);
        unordered_map<int, int> pos;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            record[i] = sum;
            if (sum % k == 0 && i > 0) {
                return true;
            }

            if (pos.find(sum % k) == pos.end()) {
                pos[sum % k] = i;
            }
            else {
                if (i - pos[sum % k] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};