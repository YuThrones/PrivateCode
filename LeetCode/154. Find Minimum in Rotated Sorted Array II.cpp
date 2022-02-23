// 跟153思路是一样的，只是边界条件多一点 ，要处理相等的情况
// 但是看了下最快解法，比我简洁很多，中间值和边界值不同则二分，否则右边界一直往左移，确实好理解很多，不过提交之后看了下时间是差不多的，只是更易于理解
class Solution {
public:
    int findMin(vector<int>& nums) {
        return process(nums, 0, nums.size() - 1);
    }
    
    int process(vector<int>& nums, int start, int end) {
        if (end - start <= 0) {
            return nums[start];
        }
        if (end - start == 1) {
            return min(nums[start], nums[end]);
        }
        
        int mid = (start + end) / 2;
        
        if (nums[start] < nums[end]) {
            return nums[start];
        }
        
        if (nums[mid] > nums[start]) {
            return process(nums, mid + 1, end);
        }
        
        if (nums[mid] < nums[start]) {
            return process(nums, start, mid);
        }
        
        return min(process(nums, mid + 1, end), process(nums, start, mid));
    }
};