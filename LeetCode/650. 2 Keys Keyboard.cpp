class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        if (n < 2) {
            return ans;
        }
        int dup = 2;
        while(n >= dup) {
            if (n % dup == 0) {
                n /= dup;
                ans += dup;
            }
            else {
                ++dup;
            }
        }
        return ans;
    }
};