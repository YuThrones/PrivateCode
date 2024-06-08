// 这道题是最长递增子序列的一个变种，要想清楚的问题是得用第一个位置的数来筛选，但是用第二数的位置来存储
// 不过最佳答案更快，直接用贪心，根据第二位从小到大排列，只要上一个记录的结尾比当前位置的开头小就可以接受
// 虽然也需要排序的时间，但是常数时间更快

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp;
        dp.push_back(pairs[0][1]);
        for (int i = 1; i < pairs.size(); ++i) {
            int index = bs(dp, pairs[i][0]);
            if (index == -1) {
                dp.push_back(pairs[i][1]);
            }
            else {
                dp[index] = min(dp[index], pairs[i][1]);
            }
        }
        return dp.size();
    }

    int bs(vector<int>& dp, int num) {
        int ans = -1;
        int l = 0;
        int r = dp.size() - 1;
        int m;
        while(l <= r) {
            m = l + ((r - l) >> 1);
            if (dp[m] >= num) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};

// 用贪心的最佳答案
#include <vector>
#include <algorithm> 
class Solution {
public:
 static bool compares(const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
    int n=pairs.size();
    if(n==0) return 0;
      std::sort(pairs.begin(), pairs.end(), Solution::compares); 
        int ans=1;
        int prevEnd=pairs[0][1];
        

        for(int i=1;i<n;i++)
        {
            if(prevEnd<pairs[i][0])  //compare the end with the start
            {
                ans++;
                prevEnd=pairs[i][1];
            }
        }
    return ans;
    }
};