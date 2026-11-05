class Solution {
public:
    int knightDialer(int n) {
        int modNum = 1e9 + 7;
        vector<int> cnt(10, 1);
        for(int i = 0; i < n - 1; ++i) {
            vector<int> nCnt(10, 0);
            for(int i = 0; i < 10; ++i) {
                for (int j : chance(i)) {
                    nCnt[j] += cnt[i];
                    nCnt[j] %= modNum;
                }
            }
            cnt = nCnt;
        }
        int ans = 0;
        for(int i = 0; i < 10; ++i) {
            ans += cnt[i];
            ans %= modNum;
        }
        return ans;
    }

    vector<int> chance(int n) {
        switch (n)
        {
            case 1:
                return {6, 8};
            case 2:
                return {7, 9};
            case 3:
                return {4, 8};
            case 4:
                return {3, 9, 0};
            case 5:
                return {};
            case 6:
                return {1, 7, 0};
            case 7:
                return {2, 6};
            case 8:
                return {1, 3};
            case 9:
                return {2, 4};
            case 0:
                return {4, 6};
        }
        return {};
    }
};