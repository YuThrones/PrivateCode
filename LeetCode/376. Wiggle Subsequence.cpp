// 其实就是最长递增子序列变种，但是写起来麻烦很多，需要考虑边际条件

#include<vector>
#include<climits>
#include<iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        return max(handle1(nums), handle2(nums));
    }

    int handle1(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> dp(nums.size() + 1);
        
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = i % 2 == 1? INT_MAX : INT_MIN;
        }

        dp[0] = INT_MAX;
        
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = res; j > 0; --j) {
                if (j % 2 == 1) {
                    // 当前是降序，找更小的
                    if (dp[j - 1] > nums[i] && nums[i] < dp[j]) {                        
                        dp[j] = nums[i];
                        res = max(res, j + 1);
                    }
                }
                else {
                    // 当前是升序，找更大的
                    if (dp[j - 1] < nums[i] && nums[i] > dp[j]) {
                        dp[j] = nums[i];
                        res = max(res, j + 1);
                    }
                }
            }
        }
        return res - 1;
    }

    int handle2(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> dp(nums.size() + 1);
        
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = i % 2 == 0? INT_MAX : INT_MIN;
        }

        dp[0] = INT_MIN;
        
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = res; j > 0; --j) {
                if (j % 2 == 0) {
                    // 当前是降序，找更小的
                    if (dp[j - 1] > nums[i] && nums[i] < dp[j]) {                        
                        dp[j] = nums[i];
                        res = max(res, j + 1);
                    }
                }
                else {
                    // 当前是升序，找更大的
                    if (dp[j - 1] < nums[i] && nums[i] > dp[j]) {
                        dp[j] = nums[i];
                        res = max(res, j + 1);
                    }
                }
            }
        }
        return res - 1;
    }
    
};

int main() {
    Solution sol;
    // vector<int> nums{1,2,3,4,5,6,7,8,9};
    vector<int> nums{3,3,3,2,5};
    cout << sol.wiggleMaxLength(nums);
    return 0;
}