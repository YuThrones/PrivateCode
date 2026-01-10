class Solution {
public:
    int findNthDigit(int n) {
        long long k = 1;
        long long start = 1;
        long long count = 9;

        while(n > k * count) {
            n -= k * count;
            k += 1;
            count *= 10;
            start *= 10;
        }

        long long num = start + (n - 1) / k;

        long long index = (n - 1) % k;
        
        return to_string(num)[index] - '0';
    }

};