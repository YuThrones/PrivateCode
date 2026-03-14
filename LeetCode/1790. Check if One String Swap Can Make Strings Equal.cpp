class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first = -1;
        int second = -1;
        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (first < 0) {
                    first = i;
                }
                else if (second < 0) {
                    second = i;
                }
                else {
                    return false;
                }
            }
        }
        if (first == -1 && second == -1) {return true;}
        if (first < 0 || second < 0) {return false;}
        return s1[first] == s2[second] && s1[second] == s2[first];
    }
};