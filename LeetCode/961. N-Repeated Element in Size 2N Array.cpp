class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                return nums[i];
            }
            record.insert(nums[i]);
        }
        return -1;
    }
};