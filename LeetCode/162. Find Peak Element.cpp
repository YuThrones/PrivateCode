// 用二分就可以解决，只需要注意边界条件
// 看了下最快解法，思路一致，但是对于0和nums.size()-1的情况，他直接根据边界数值算出答案，确实应该更快一点点
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        bool lg, rg;
        while(start < end) {
            mid = (start + end) / 2;
            
            lg = (mid - 1 < 0 || nums[mid - 1] < nums[mid]);
            rg = (mid + 1 > nums.size() - 1 || nums[mid + 1] < nums[mid]);
            
            if (lg && rg) {
                return mid;
            }
            else if (lg && !rg) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            
        }
        return start;
    }
};