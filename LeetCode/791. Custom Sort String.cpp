class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for (auto c : s) {
            count[c - 'a']++;
        }

        string ans = "";

        for (auto o : order) {
            if (count[o - 'a'] > 0) {
                ans += string(count[o - 'a'], o);
                count[o - 'a'] = 0;
            }
        }

        for(int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                ans += string(count[i], 'a' + i);
            }
        }
        return ans;
    }
};