# 自己没想出很好的办法，看了下讨论，采用的方法很巧妙
# 用一个vector存储长度从0到n，以最左边开始的字符串的划分数目，
# 然后从最左边开始遍历，分别以当前位置为中心，进行奇数个和偶数个字符的回文检查
# 如果一个数是回文，那么以右边界为终结，这个长度的字符串的最小划分个数，是已知的最小划分个数，和以左边界为终结的字符串的最小划分个数-1中的较小值

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,n-1);
        dp[0] = -1;
        for(int i=0;i<n;i++)
        {
            //odd length
            int l = i , r = i;
            while(l>=0 and r<n and s[l] == s[r])
            {
                dp[r+1] = min(dp[r+1],1+dp[l]);
                l--;
                r++;
            }
            //even length
            l = i , r = i+1;
            while(l>=0 and r<n and s[l] == s[r])
            {
                dp[r+1] = min(dp[r+1],1+dp[l]);
                l--;
                r++;
            }
        }
        return dp[n];
    }
};