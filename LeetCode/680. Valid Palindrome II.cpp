class Solution {
public:
    bool validPalindrome(string s) {
        return check(s, 0, s.size() - 1, 1);
    }

    bool check(string& s, int start, int end, int count) {
        if (start == end) {
            return true;
        }
        for (int i = 0; start + i < end - i; ++i) {
            if (s[start + i] != s[end - i]) {
                if (count <= 0) {return false;}
                return check(s, start + i + 1, end - i, count - 1) || check(s, start + i, end - i - 1, count - 1);
            }
        }
        return true;
    }
};