// 思路很简单，排序，从最大值往下搜一下第一个满足的值即可，复杂度O(nlogn)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = citations.size(); i > 0; --i) {
            if (citations[citations.size() - i] >= i) return i;
        }
        return 0;
    }
};