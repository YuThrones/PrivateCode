class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> count;
        for (auto i : deck) {
            count[i] += 1;
        }
        int last = -1;
        for (auto it : count) {
            if (it.second <= 1 || (last != -1 && last != it.second)) {
                return false;
            }
            last = it.second;
        }
        return true;
    }
};