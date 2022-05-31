// 两个哈希表，双向映射，注意边界条件判断，比如长度不等

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> record;
        unordered_map<string, char> record1;
        int start = 0;
        int pIndex = 0;
        for (int i = 0; i <= s.length(); ++i) {
            if (i < s.length() && s[i] != ' ') continue;
            string temp(s, start, i - start);
            start = i + 1;
            char tempChar = pattern[pIndex];
            if (record.find(tempChar) == record.end() && record1.find(temp) == record1.end()) {
                record[tempChar] = temp;
                record1[temp] = tempChar;
            }
            else if (record[tempChar] != temp || record1[temp] != tempChar) {
                return false;
            }
            ++pIndex;
        }
        return pIndex == pattern.length();
    }
};