class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = n - 1; j > i + ans; --j) {
                if (colors[i] != colors[j]) {
                    if (j - i > ans) {
                        ans = j - i;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};