// 双哈希表解决，保证两边映射一致即可
// 看了下最快答案，因为是char所以直接用了数组，不过思路是一样的，只存在常数级差别

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        if (s.empty()) {
            return false;
        }
        
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < s.length(); ++i) {
            if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if ((m1[s[i]] != t[i]) || (m2[t[i]] != s[i])) {
                return false;
            }
            
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    cout << s.isIsomorphic("badc", "baba");
    return 0;
}