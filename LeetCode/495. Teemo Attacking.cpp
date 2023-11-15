// 很简单的题目，一个毒要么持续要下次被攻击，要么走完一个完整持续时间，取较小值即可
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if (!timeSeries.size()) return res;
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            res += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        res += duration;
        return res;
    }
};