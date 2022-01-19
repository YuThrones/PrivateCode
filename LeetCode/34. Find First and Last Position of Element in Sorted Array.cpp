// 基础的二分搜索，先二分找到一个相等值，然后往两边遍历搜索即可，只需要注意边界条件
// 最快答案是两个二分，一个二分找到最左，一个二分找到最右，遇到极端情况确实更佳

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int start = 0;
        int end = nums.size();
        int mid;
        int i;
        while(start < end) {
            mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid;
            }
            else {
                for (i = mid - 1; i >= 0 && nums[i] == target; --i) {}
                ans[0] = i + 1;
                for (i = mid + 1; i < nums.size() && nums[i] == target; ++i) {}
                ans[1] = i - 1;
                break;
            }
        }
            
        return ans;
    }
};