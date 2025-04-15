class Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> result(2, 0);
    
            if (nums[0] != 1) {
                result[1] = 1;
            }
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] == nums[i + 1]) {
                    result[0] = nums[i];
                }
                if (nums[i] + 1 < nums[i + 1]) {
                    result[1] = nums[i] + 1;
                }
            }
            if (result[1] == 0) {
                result[1] = nums.size();
            }
            return result;
        }
    };