// 这道题第一反应是想到用容量为k的大根堆来解决，但是k太大时时间爆炸
// 然后很容易想到打印出数字看看规律，发现需要计算数字个数来跳过，但是这个编码很难写，
// 看了下别人解答，代码很简洁，但是其实很不好理解

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            while (first <= n) {
                step += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (step <= k) {
                ++cur;
                k -= step;
            } else {
                cur *= 10;
                --k; 
            }
        }
        return cur;
    }
};