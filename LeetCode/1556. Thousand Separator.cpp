class Solution {
public:
    string thousandSeparator(int n) {
        int count = 0;
        string ans = "";
        while(n > 0) {
            ans = to_string(n % 10) + ans;
            ++count;
            n /= 10;
            if (count % 3 == 0 && n > 0) {
                ans = "." + ans;
            }
        }
        return ans;
    }
};