// 直接用上一题方法可解，加上二分搜索可以更快

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (!citations.size()) return 0;
        int l = 0;
        int r = citations.size();
        int m;
        while(l < r) {
            m = (l + r) / 2;
            if (citations[m] < citations.size() - m) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return citations.size() - l;
    }
};