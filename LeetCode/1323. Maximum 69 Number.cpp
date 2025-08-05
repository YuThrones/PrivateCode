class Solution {
public:
    int maximum69Number (int num) {
        int mod = 10;
        while(num >= mod) {
            mod *= 10;
        }
        mod /= 10;
        int temp = num;
        while(temp > 0) {
            if (temp / mod == 6) {
                return num + mod * 3;
            }
            temp = temp % mod;
            mod /= 10;
        }
        return num;
    }
};