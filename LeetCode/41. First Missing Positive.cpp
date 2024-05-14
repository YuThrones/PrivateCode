#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r) {
            // 当前位置满足要求
            if (nums[l] == l + 1) {
                ++l;
            }
            // 要么当前位置的数不在 l+1到r这个范围内，要么已经重复了，直接发送到最后垃圾区
            else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) {
                swap(nums[l], nums[--r]);
            }
            // 当前位置的数在l+1到r+1范围内，而且目前该位置还没被同样数字占据，直接发送过去
            else {
                swap(nums[l], nums[nums[l] - 1]);
            }
        }
        return l + 1;
    }
};
