// 这道题没想出来，看答案也看了很久才懂，事实上非常巧妙，如果前面小的数都加起来，还无法达到，那么用大的数也达不到了，直接加一个patch即可

class Solution {
public:
    int minPatches(vector<int>& a, int n) {
        #define int long long
        int ans = 0, high = 0;
        for(int ai:a) {
            while (high < ai - 1 && high < n)
                high += high + 1, ++ans;
            high += ai;
            if (high >= n) break;
        }
        while (high < n)
            high += high + 1, ++ans;
        #undef int
        return ans;
    }
};