// 这题很简单，一个排序，然后两个指针分别划两个数组，保证s[j]大于等于g[i]，找到满足数量的饼干数量就行

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int res = 0;
        while(i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                ++i;
                ++j;
                ++res;
            }
            else {
                ++j;
            }
        }
        return res;
    }
};