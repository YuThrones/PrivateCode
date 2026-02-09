class Solution {
public:
    int totalMoney(int n) {
        int ans = 1;
        int cur = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 7 == 1) {
                cur -= 5;
            }
            else {
                cur += 1;
            }
            ans += cur;
        }
        return ans;
    }
};