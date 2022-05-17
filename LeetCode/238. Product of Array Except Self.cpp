// 直接算出所有数的积，需要注意0得另外处理，统计0的数量
// 然后第二次遍历的时候再计算答案，如果是0，并且没有其他0，则是之前所有的积，如果还有其他0，就是0
// 如果不是0，只需要看看有没有0即可

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if (!nums.size()) return res;

        int total = 1;
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                total *= nums[i];    
            }
            else {
                zeroCount++;
            }
            
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (zeroCount) res.push_back(0);
                else res.push_back(total / nums[i]);
            }
            else {
                if (zeroCount > 1) res.push_back(0);
                else res.push_back(total);
            }
        }
        return res;
    }
};