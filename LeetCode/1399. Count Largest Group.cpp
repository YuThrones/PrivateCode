class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>count (1000, 0);
        int maxSize = 0;
        for(int i = 1; i <= n; ++i) {
            int num = getValue(i);
            maxSize = max(maxSize, ++count[num]);
        }
        int ans = 0;
        for (int i = 0; i < 1000; ++i) {
            if (count[i] == maxSize) {
                ++ans;
            }
        }
        return ans;
    }

    int getValue(int n) {
        int ans = 0;
        while(n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
};