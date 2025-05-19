class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.length() - 1;
        while(start < end && start < s.length() && end >= 0) {
            while (start < s.length() && !isalpha(s[start])) {
                ++start;
            }
            while (end >= 0 && !isalpha(s[end])) {
                --end;
            }
            if (start < end) {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                ++start;
                --end;
            }
        }
        return s;
    }
};