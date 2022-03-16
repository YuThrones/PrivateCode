// 最容易想到的就时假定以某个位置为截止进行递归，然后主函数传入整个vector的size
// 再进一步优化改成递推即可

class Solution {
public:
    int rob(vector<int>& nums) {
        // return process(nums, nums.size());
        return process2(nums);
    }
    
    int process(vector<int>& nums, int end) {
        if (end <= 0) {
            return 0;
        }
        if (end == 1) {
            return nums[0];
        }
        if (end == 2) {
            return max(nums[0], nums[1]);
        }
        return max(process(nums, end - 1), process(nums, end - 2) + nums[end - 1]);
    }
    
    int process2(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int record[nums.size()];
        record[0] = nums[0];
        record[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            record[i] = max(record[i - 1], record[i - 2] + nums[i]);
        }
        return record[nums.size() - 1];
    }
};