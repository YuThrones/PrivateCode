class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> store;
        int num = 0;
        int last = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                store[s[i] - '0'] = s.substr(last, i - last);
                last = i + 2;
                num = max(num, s[i] - '0');
            }
        }
        string ans;
        for(int i = 1; i <= num; ++i) {
            if (i > 1) {
                ans += " ";
            }
            ans += store[i];
        }
        return ans;
    }
};