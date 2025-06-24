// 解法很多，选择了最简单粗暴的一种，直接前面连续，后面补个相反数

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        result.reserve(n);
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            result.emplace_back(i);
            sum += i;
        }
        result.emplace_back(-sum);
        return result;
    }
};