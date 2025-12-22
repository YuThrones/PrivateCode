class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if (n % 2 == 1) {
            ans += string(n, 'a');
        }
        else {
            ans += string(n - 1, 'a');
            ans += "b";
        }
        return ans;
    }
};