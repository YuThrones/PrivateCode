// 这题知道要先构造前面，但是没有什么思路怎么处理，问了下AI，需要按小和大交替加入的顺序处理

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int low = 1;
        int high = k + 1;

        while(low <= high) {
            ans.push_back(low);
            if (low != high) {
                ans.push_back(high);
            }
            ++low;
            --high;
        }

        for (int i = k + 2; i <= n; ++i) {
            ans.push_back(i);
        }

        return ans;
    }
};