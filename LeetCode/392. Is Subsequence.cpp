// 两个索引往右划，判断能不能到结尾就行，不需要递归

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        int r = 0;
        while(l < s.length() && r < t.length()) {
            if (s[l] == t[r]) {
                ++l;
                ++r;
            }
            else {
                ++r;
            }
        }
        return l == s.length();
    }
    
};