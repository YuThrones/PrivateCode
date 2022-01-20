// 二分查找，通过奇偶性是否对应，检查出问题的是在前半段还是后半段，注意边界条件即可
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        int mid = 0;
        while(start < end - 1) {
            mid = (start + end) / 2;
            if (mid == end - 1) {
                
            }
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    start = mid + 2;
                }
                else {
                    end = mid + 1;
                }
            }
            else {
                if (nums[mid] == nums[mid - 1]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
        }
        return nums[start];
    }
};