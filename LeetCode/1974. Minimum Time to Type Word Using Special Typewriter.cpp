class Solution {
public:
    int minTimeToType(string word) {
        char last = 'a';
        int ans = 0;
        for(char c : word) {
            if (last != c) {
                int temp = (26 + c - last) % 26;
                if (temp > 12) {
                    temp = 26 - temp;
                }
                ans += temp;
                last = c;
            }
            ++ans;
        }
        return ans;
    }
};