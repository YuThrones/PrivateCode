// 这道题关键要从例子看出怎么算，首先是找到频率最大的字母，首先满足他的周期，如果有多个，就需要同时满足。
// 然后再算出满足周期最小的字母数量，如果比原本的tasks多，说明要补idle，如果少，说明没有idle，tasks的总数就是答案。

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char c : tasks) {
            count[c - 'A']++;
        }
        int sum = 0;
        int maxNum = 0;
        for (int i = 0; i < count.size(); ++i) {
            sum += count[i];
            maxNum = max(maxNum, count[i]);
        }
        int sameNum = 0;
        for (int i = 0; i < count.size(); ++i) {
            if(count[i] == maxNum) {sameNum++;}
        }
        // cout << sum << " " << maxNum << " " << sameNum << endl;
        return max(sum, (maxNum - 1) * (n + 1) + sameNum);
    }
};