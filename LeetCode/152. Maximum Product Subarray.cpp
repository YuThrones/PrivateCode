// 想到一个解挺简单的，两个数组，一个存当前位置结尾的最大积，一个存当前位置结尾的最小积，然后根据当前位置是否是负数判断使用即可
// 看了下最优解，思路完全一致，实际复制跑时间也差不多
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }
        vector<int> minProduct;
        vector<int> maxProduct;
        minProduct.push_back(nums[0]);
        maxProduct.push_back(nums[0]);
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                maxProduct.push_back(max(nums[i], nums[i] * minProduct[i - 1]));
                minProduct.push_back(min(nums[i], nums[i] * maxProduct[i - 1]));
            }
            else {
                maxProduct.push_back(max(nums[i], nums[i] * maxProduct[i - 1]));
                minProduct.push_back(min(nums[i], nums[i] * minProduct[i - 1]));
            }
            res = max(res, maxProduct[i]);
        }
        return res;
    }
};