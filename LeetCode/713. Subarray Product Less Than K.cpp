// 前面连续一段结果复用可以大大减少时间

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // Edge case

        int i = 0, j = 0, count = 0, product = 1;

        while (j < nums.size()) {
            product *= nums[j];

            while (product >= k) {
                product /= nums[i];
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = i; j < nums.size(); ++j) {
                product *= nums[j];
                if (product >= k) {
                    break;
                }
                ++ans;
            }
        }
        return ans;
    }
};