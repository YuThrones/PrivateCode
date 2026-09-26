// 一开始只考虑了左右两边流量的差值，但是忽略了作为一个单独的节点，往外要送出多少个衣服这件事，也就是只考虑了入，没有考虑出

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if(sum % n != 0) {
            return -1;
        }
        int per = sum / n;
        vector<int> left(n, 0);
        int total = 0;
        for(int i = 0; i < n; ++i) {
            total += machines[i];
            if (i > 0) {
                left[i] = max(left[i - 1], (i + 1) * per - total);
            }
            else {
                left[i] = max(0, (i + 1) * per - total);
            }
        }
        vector<int> right(n, 0);
        total = 0;
        for(int i = n - 1; i >= 0; --i) {
            total += machines[i];
            if (i < n - 1) {
                right[i] = max(right[i + 1], (n - i) * per - total);
            }
            else {
                right[i] = max(0, (n - i) * per - total);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, max(left[i], right[i]));
        }
        for(int x : machines) {
            ans = max(ans, x - per);
        }
        return ans;
    }
};