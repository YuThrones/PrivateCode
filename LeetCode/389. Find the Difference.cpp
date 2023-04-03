class Solution {
public:
    char findTheDifference(string s, string t) {
        int sc[26] = {};
        memset(sc, 0, sizeof(sc));
        for (auto c: s) sc[c - 'a'] -= 1;
        for (auto c: t) sc[c - 'a'] += 1;
        for (int i = 0; i < 26; ++i) {
            if (sc[i] > 0) return 'a' + i;
        }
        return 'a';
    }
};