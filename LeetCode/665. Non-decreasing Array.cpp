class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        return check(nums, 1);
    }

    bool check(vector<int>& nums, int count) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (count == 0) {
                    return false;
                }
                int cur = nums[i];
                nums[i] = nums[i + 1];
                bool res = check(nums, count - 1);
                if (res) {return true;}
                nums[i] = cur;
                
                cur = nums[i + 1];
                nums[i + 1] = nums[i];
                res = check(nums, count - 1);
                if (res) {return true;}
                return false;
            }
        }
        return true;
    }
};