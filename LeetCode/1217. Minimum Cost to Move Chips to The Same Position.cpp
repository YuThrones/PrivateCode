// 其实很简单，想明白了就是取奇偶数的较小值

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> count(2, 0);
        for(int n : position) {
            count[n % 2]++;
        }
        return min(count[0], count[1]);
    }
};