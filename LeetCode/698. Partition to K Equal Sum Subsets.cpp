class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % k != 0) {
            return false;
        }
        int part = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > part) {return false;}
        vector<int> buck(k, 0);
        return cal(nums, part, buck, 0);
    }

    bool cal(vector<int>& nums, int target, vector<int> buck, int index) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        if (index >= nums.size()) {return true;}

        int cur = nums[index];
        for (int i = 0; i < buck.size(); ++i) {
            if (cur + buck[i] > target) {continue;}
            if (i > 0 && buck[i] == buck[i - 1]) {continue;}
            buck[i] += cur;
            if(cal(nums, target, buck, index + 1)) {
                return true;
            }
            buck[i] -= cur;
        }
        
        return false;
    }
};