class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& c : accounts) {
            int temp = 0;
            for (int w : c) {
                temp += w;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};