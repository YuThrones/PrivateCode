class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        vector<int> result(n + 1);
        result[0] = 0;
        result[1] = 1;
        int ret = 0;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                result[i] = result[i / 2];
            }
            else {
                result[i] = result[i / 2] + result[i / 2 + 1];
            }
            ret = max(ret, result[i]);
        }
        return ret;
    }
};