class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n / 2; ++i) {
            if (isok(i) && isok(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }

    bool isok(int i) {
        while(i > 0) {
            if (i % 10 == 0) {
                return false;
            }
            i /= 10;
        }
        return true;
    }
};