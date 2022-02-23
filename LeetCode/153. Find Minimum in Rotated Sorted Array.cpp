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
        if (nums[mid] > nums[start] && nums[mid] > nums[end]) {
            return process(nums, mid + 1, end);
        }
        
        if (nums[mid] < nums[start] && nums[mid] < nums[end]) {
            return process(nums, start, mid);
        }
        
        return nums[start];
    }
};