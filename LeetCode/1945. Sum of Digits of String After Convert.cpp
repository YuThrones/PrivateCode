class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(char c : s) {
            temp += to_string(c - 'a' + 1);
        }
        int sum = 0;
        for(int i = 0; i < k; ++i) {
            sum = 0;
            for(char c : temp) {
                sum += (c - '0');
            }
            temp = to_string(sum);
        }
        return sum;
    }
};