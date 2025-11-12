class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<pair<char, int>> check{
            {'b', 1},
            {'a', 1},
            {'l', 2},
            {'o', 2},
            {'n', 1},
        };
        unordered_set<char> cset {'a', 'b', 'l', 'o', 'n'};
        vector<int> count(27, 0);
        for (char c : text) {
            if(cset.find(c) != cset.end()) {
                count[c - 'a']++;
            }
        }
        int ans = INT_MAX;
        for(auto p : check) {
            ans = min(ans, count[p.first - 'a'] / p.second);
        }
        return ans;
    }
};