最佳答案直接把可能是素数数量写死了，要更快一些


class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        while(left <= right) {
            int cnt = __builtin_popcount(left);
            if(cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 || cnt == 13 || cnt == 17 || cnt == 19) ++ans;
            ++left;
        }
        return ans;
    }
};

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            int count = 0;
            int temp = i;
            while(temp > 0) {
                if (temp & 1) {
                    ++count;
                }
                temp >>= 1;
            }
            if (isPrime(count)) {
                ++result;
            }
        }
        return result;
    }

    inline bool isPrime(int num) {
        static map<int, bool> cache;
        if (num <= 1) {
            return false;
        }
        if (cache.find(num) != cache.end()) {
            return cache[num];
        }
        for (int i = 2; i < num; ++i) {
            if (num % i == 0) {
                cache[num] = false;
                return false;
            }
        }
        cache[num] = true;
        return true;
    }
};