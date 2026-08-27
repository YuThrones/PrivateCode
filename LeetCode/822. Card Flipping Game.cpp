class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> invalid;
        int n = fronts.size();
        for(int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                invalid.insert(fronts[i]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if (invalid.find(fronts[i]) == invalid.end()) {
                ans = min(ans, fronts[i]);
            }
            if (invalid.find(backs[i]) == invalid.end()) {
                ans = min(ans, backs[i]);
            }
        }
        if(ans == INT_MAX){
            ans = 0;
        }
        return ans;
    }
};