// 思路非常简单粗暴，每次遇到等于val的位置，就把vector最后一个数拉过来，然后删除最后一个数就行
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                ++k;
                nums[i] = nums[nums.size() - 1];
                nums.pop_back();
                continue;
            }
            ++i;
        }
        return nums.size();
    }
};