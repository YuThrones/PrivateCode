class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& nums) {
            int i = 0;
            int j = 1;
            for (; i < nums.size() && j < nums.size();) {
                if (nums[i] % 2 == 1) {
                    swap(nums[i], nums[j]);
                    j += 2;
                }
                else if (nums[j] % 2 == 0) {
                    swap(nums[i], nums[j]);
                    i += 2;
                }
                else {
                    i += 2;
                    j += 2;
                }
            }
            return nums;
        }
    };