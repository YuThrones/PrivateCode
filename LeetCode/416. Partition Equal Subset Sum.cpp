// 自己写了动态规划+记忆存储可以解，但是速度不够快
// 看了下最佳答案，用bitset解决的，利用了数据量不大的特点，非常的优雅，只需要一次遍历加上与运算就可以，值得学习

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 2 == 1) return false;
        vector<unordered_map<int, bool>> dp;
        for (int i = 0; i < nums.size(); ++i) {
            dp.push_back(unordered_map<int, bool>());
        }
        return cal(nums, 0, sum / 2, dp);
    }
    
    bool cal(vector<int>& nums, int start, int target, vector<unordered_map<int, bool>>& dp) {
        if (target == 0) return true;
        if (target < 0) {
            return false;
        }
        if (start >= nums.size()) {
            return false;
        }
        
        if (dp[start].find(target) != dp[start].end()) {
            return dp[start][target];
        }
        
        bool res = cal(nums, start + 1, target, dp); // 不要当前位置
        if (res) {
            dp[start][target] = res;
            return res;
        }
        res = cal(nums, start + 1, target - nums[start], dp); // 要当前位置
        dp[start][target] = res;
        return res;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        bitset<10001> possible; //maxPossibleSum=20000
        possible[0]=1;
        for(auto& x:nums)
            possible|=possible<<x;
        return possible[sum>>1];
    }
};