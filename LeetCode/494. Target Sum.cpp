// 我是直接根据题意写代码，所以可能性有2的n次方种，然后再剪枝，根据可变范围，可能复杂度是 n * m * 2
// 最快方法是，转化成在nums里面取若干数加起来为 target/2 这个数的个数，则是填n * m的表，应该要快一点

class Solution {
public:
    int countSubsets(vector<int>& nums, int n, int M)
    {
        int t[n+1][M+1];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }

        return t[n][M];  
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target);
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int M=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        
         return countSubsets(nums, n, M);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size());
        return yu(nums, 0, target, dp);
    }
    
    int yu(vector<int>& nums, int start, int target, vector<unordered_map<int, int>>& dp) {
        if (start >= nums.size()) return 1 ? (target == 0) : 0;
        if (dp[start].find(target) != dp[start].end()) return dp[start][target];
        int ans = 0;
        ans += yu(nums, start + 1, target - nums[start], dp);
        ans += yu(nums, start + 1, target + nums[start], dp);
        dp[start][target] = ans;
        return ans;
    }
};