// 太久没做DP了，一下子没想出来
// 看了下AI，核心思路就是动态规划，dp[i][j]认为用 1 到 i作为数字，能拼出j的逆序对的情况有多少
// 而 i + 1的逆序对的数量，就是把 i + 1插到已经排好的可能性当中，因为 i + 1比前面所有数字大
// 所以可以控制往前插几位就是有几个逆序对，把 1 到 i 的范围算好的dp都利用起来
// 然后就是做前缀和优化，以及空间压缩

class Solution {
public:
    int kInversePairs(int n, int k) {
        int modNum = 1e9 + 7;
        if(k > (n - 1) * n / 2) {return 0;}

        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; ++i) {
            vector<int> ndp(k + 1, 0);
            long long windows = 0;
            for(int j = 0; j <= k; ++j) {
                windows += dp[j];

                if(j - i >= 0) {
                    windows -= dp[j - i];
                }

                windows = (windows + modNum) % modNum;

                ndp[j] = windows;
            }
            dp.swap(ndp);
        }

        return dp[k];
    }
};

// 最快答案只是提前把所有可能的答案算出来了，算法上没什么不一样的
class Solution {
private:
    inline static vector<vector<int>> dp = []() {
        const int mod = 1e9+7;
        const int ma = 1000;
        vector<vector<int>> res(ma+1, vector<int>(ma+1, 0));

        for(int i=1; i<=ma; i++) res[i][0] = 1;

        for(int i=2; i<=ma; i++){
            int l = 0, r = 0;
            int sum = 0;

            for(int j=1; j<=ma; j++){
                while(r <= j){
                    sum += res[i-1][r];
                    sum %= mod;
                    r++;
                }

                if(r - l > i) {
                    sum = (sum - res[i-1][l] + mod) % mod;
                    l++;
                }

                if(sum == 0) break;

                res[i][j] = sum;
            }
        }

        return res;
    }();

public:
    int kInversePairs(int n, int k) {
        return dp[n][k];
    }
};