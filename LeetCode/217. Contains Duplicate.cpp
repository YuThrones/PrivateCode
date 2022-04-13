// 最简单的就是用一个set存一下已经遇到的，然后遇到重复时返回true
// 看了下最快答案，采取的方式是sort之后检查前后是否有相同，理论上复杂度应该不会比用set低

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto i: nums) {
            if (s.find(i) != s.end()) {
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};