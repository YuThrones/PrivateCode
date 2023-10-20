// 这道题的解法很简单，思路也很巧妙，n-1个数+1，那其实理解成最大的数减1就行了，那么题目就转化成，多久可以把所有数减小到最小的数那么大，求出最小值之后算一下这个值就行了

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto &n: nums) {
            res += (n - minNum);
        }
        return res;
    }
};