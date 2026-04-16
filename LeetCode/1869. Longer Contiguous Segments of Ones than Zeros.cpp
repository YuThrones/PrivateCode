class Solution {
public:
    bool checkZeroOnes(string s) {
        int count0 = 0;
        int count1 = 0;
        int max0 = 0;
        int max1 = 1;
        for (auto c : s) {
            if (c == '0') {
                if (count1 > 0) {
                    max1 = max(max1, count1);
                    count1 = 0;
                }
                ++count0;
            }
            else {
                if (count0 > 0) {
                    max0 = max(max0, count0);
                    count0 = 0;
                }
                ++count1;
            }
        }
        max1 = max(max1, count1);
        max0 = max(max0, count0);
        return max1 > max0;
    }
};