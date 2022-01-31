// 没研究出最快的方法，看了下讨论，事实上思路是，如果一圈下来累加和大于等于0，必然存在解，这时候只需要找到第一个一直往后推不会出现负数的index就行
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(), curr = -1, total = 0, res = 0;
        for (int i = 0, n; i < len; i++) {
            n = gas[i] - cost[i];
            if (curr < 0 && n >= 0) {
                res = i;
                curr = 0;
            }
            curr += n;
            total += n;
        }
        return total >= 0 ? res : -1;
    }
};