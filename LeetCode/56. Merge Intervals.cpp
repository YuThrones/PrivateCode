// 这题的解法很简单，先按开始区间排序，然后把前后的合并放进新的vector，遍历处理完所有区间即可，注意边界条件处理就行
bool comp(vector<int>& x, vector<int>& y) {
    return x[0] < y[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res = vector<vector<int>>();
        vector<int> cur = intervals[0];
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > cur[1]) {
                res.push_back(cur);
                cur = intervals[i];
            }
            else {
                cur[0] = min(cur[0], intervals[i][0]);
                cur[1] = max(cur[1], intervals[i][1]);
            }
        }
        res.push_back(cur);
        return res;
    }
    
};