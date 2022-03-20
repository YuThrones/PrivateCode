// 固定范围内的素数，可以用素数筛法解决，其中可以通过剪枝做一点优化。比如每次只筛掉大于等于自己平方的，因为更小的肯定被其他数筛过了
// 看了下最快答案，有点投机取巧的意思，把一个很大数目的答案求出来，然后所以解都在里面取，思路还是素数筛法

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        bool prime[n];
        for (int i = 0; i < n; ++i) {
            prime[i] = true;
        }
        
        for (int i = 2; i * i < n; ++i) {
            if (!prime[i]) {
                continue;
            }
            int j = i * i;
            while(j < n) {
                prime[j] = false;
                j += i;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ++count;    
            }
        }
        return count;
    }
};