// 直接用哈希表存一下再看看是否一致就行，最快解法是用26位的数组。思路都一样

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> m1;
        int count = s.length();
        for (auto c: s) m1[c] += 1;
        for (auto c: t) {
            if (m1[c] > 0) {
                count -= 1;
                m1[c] -= 1;
            }
        }
        return count == 0;
    }
};