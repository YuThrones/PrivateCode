class Solution {
public:
    unordered_set<char> vowel {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        if (s.length() % 2 == 1) {
            return false;
        }
        int ca = 0;
        int cb = 0;
        bool isA = true;
        for (int i = 0; i < s.length(); ++i) {
            if (i == s.length() / 2) {
                isA = false;
            }
            if (vowel.find(s[i]) != vowel.end()) {
                if (isA) {
                    ++ca;
                }
                else {
                    ++cb;
                }
            }
        }
        return ca == cb;
    }
};