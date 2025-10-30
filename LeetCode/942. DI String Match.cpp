// 这道题要用贪心，用low和high维护最大最小值，遇到I就给他最小值，并且low加一，遇到D就给最大值，high减少

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.length();
        int low = 0;
        int high = size;
        vector<int> ans(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            if(s[i] == 'I') {
                ans[i] = low;
                ++low;
            }
            else {
                ans[i] = high;
                --high;
            }
        }
        ans[size] = high;
        return ans;
    }
};