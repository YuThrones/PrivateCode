// 跟有序的二分思路是一样的，唯一的区别是判断的时候还要注意对应区间是否可能存在旋转的情况，可以通过当前节点和两边端点是否保持有序性来判断
// 最佳答案是先找到旋转点，然后划分旋转点之后在两边分别找，虽然代码更麻烦，但是思路更清晰，确实更好
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid;
        int ans = -1;
        while(start < end) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                if (nums[mid] > nums[nums.size() - 1] || target <= nums[nums.size() - 1]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            else {
                if (target >= nums[0] || nums[mid] < nums[0]) {
                    end = mid;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        
        return ans;
    }
};