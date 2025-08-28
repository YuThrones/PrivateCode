class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> dct;
        for (auto& d : dominoes) {
            int a = d[0];
            int b = d[1];
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            ++dct[a * 10 + b];
        }
        int ans = 0;
        for (auto it: dct) {
            ans += it.second * (it.second - 1) / 2;
        }
        return ans;
    }
};