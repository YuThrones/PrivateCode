class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights.begin(), heights.end());
        sort(temp.begin(), temp.end());
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != temp[i]) {
                ++result;
            }
        }
        return result;
    }
};