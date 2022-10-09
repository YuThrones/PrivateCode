// 按右边界从小到大排序，然后一个贪心从前到后选，把不能满足前面的都放弃就可以解决了
// 因为最小右边界如果和他冲突，选择最小右边界必然更好，因为干扰到右边的概率更小
// 因为我作了排序，复杂度是O(nlogn)
// 最佳答案思路完全一致，只是把vector变成了pair，应该是避免了排序时有复制的情况，所以更快

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] > b[0];
}

class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // 先排序然后把开头相同但是结尾更大的去掉
        sort(intervals.begin(), intervals.end(), cmp);
        
        int ans = 0;
        int last = INT_MIN;
        for (auto v: intervals) {
            if (v[0] >= last) {
                last = v[1];
            }
            else {
                ++ans;
            }
        }
        return ans;
    }
};