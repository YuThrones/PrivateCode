// 虽然做出来了，但是太慢了，用unordered_map比多维数组慢太多了，而且可以用DP替代递归
// 而且最快答案是直接return true，因为先手必胜。。。

#include <vector>
#include <numeric>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[505][505];
    vector<int> pre; //前缀和

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        pre.resize(n+1,0);
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+piles[i];
        int total = pre[n];
        int first = dfs(piles,0,n-1);
        return first > total / 2;
    }

    //返回：当前玩家在区间[l,r]可以拿到的最大石子
    int dfs(vector<int>& piles, int l, int r){
        if(l>r) return 0;
        if(l == r) return piles[l];
        if(dp[l][r] != -1) return dp[l][r];

        int sumLR = pre[r+1] - pre[l]; // [l,r]区间总和
        //拿左边
        int takeLeft = piles[l] + ( (pre[r+1]-pre[l+1]) - dfs(piles,l+1,r) );
        //拿右边
        int takeRight = piles[r] + ( (pre[r]-pre[l]) - dfs(piles,l,r-1) );

        return dp[l][r] = max(takeLeft, takeRight);
    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        unordered_map<long long, int> rec;
        return getMax(piles, 0, piles.size() - 1, total, rec) > total / 2;
    }

    int getMax(vector<int>& piles, int start, int end, int sum, unordered_map<long long, int>& rec) {
        if(start > end) {
            return 0;
        }
        if (start == end) {
            return piles[start];
        }
        if(rec.find(getHash(start, end)) != rec.end()) {
            return rec[getHash(start, end)];
        }
        int ans = 0;
        int temp = sum - getMax(piles, start + 1, end, sum - piles[start], rec);
        ans = max(ans, temp);
        temp = sum - getMax(piles, start, end - 1, sum - piles[end], rec);
        ans = max(ans, temp);
        rec[getHash(start, end)] = ans;
        return ans;
    }

    long long getHash(int a, int b) {
        return ((long long) a << 32) | b;
    }
};