class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        for (auto & r: rectangles) {
            int len = min(r[0], r[1]);
            maxLen = max(maxLen, len);
        }
        int ans = 0;
        for (auto & r: rectangles) {
            int len = min(r[0], r[1]);
            if (len == maxLen) {
                ++ans;
            }
        }
        return ans;
    }
};