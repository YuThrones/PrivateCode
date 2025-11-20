class Solution {
public:
    int numPrimeArrangements(int n) {
        int mod = 1000000007;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= n; ++i) {
            for(int j = i; i * j <= n; ++j) {
                isPrime[i * j] = false;
            }
        }
        int primeNum = 0;
        for(int i = 2; i <= n; ++i) {
            if(isPrime[i]) {
                primeNum++;
            }
        }
        long long ansP = 1;
        long long ansL = 1;
        for(int i = primeNum; i > 0; --i) {
            ansP = ansP * i % mod;
        }
        for(int i = n - primeNum; i > 0; --i) {
            ansL = ansL * i % mod;
        }
        return ansP * ansL % mod;
    }
};