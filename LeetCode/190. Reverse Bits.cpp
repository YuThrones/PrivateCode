// 这道题比较简单，用&的方式得出最后一个数，然后加到答案上就行

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) 
            res = res << 1;
            res |= n % 2;
            n = n >> 1;
        }
        return res;
    }
};