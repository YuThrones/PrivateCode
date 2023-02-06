// 没什么好说的，记录下数量就行，只需要注意用数组比字典更快

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {};
        for(auto c: magazine) {
            map[c - 'a'] += 1;
        }
        for(auto c: ransomNote) {
            if (map[c - 'a'] <= 0) {
                return false;
            }
            map[c - 'a'] -= 1;
        }
        return true;
    }
};