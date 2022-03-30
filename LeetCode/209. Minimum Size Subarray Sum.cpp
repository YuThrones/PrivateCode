// 前后两个指针来记录范围，比target小移动后之前，大于target移动前指针，找到答案即可

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int res = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        
        while(end < nums.size()) {
            while(sum < target && end < nums.size()) {
                sum += nums[end];
                ++end;
            }
            while(sum - nums[start] >= target) {
                sum -= nums[start];
                ++start;
            }
            if (sum >= target) {
                res = min(res, end - start);            
            }
            sum -= nums[start];
            ++start;
        }
        
        if (res == INT_MAX) {
            res = 0;
        }
        return res;
    }
};