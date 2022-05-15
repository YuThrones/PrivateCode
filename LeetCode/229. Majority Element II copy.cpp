// 用正常逻辑写很容易通过，但是不是最快
// 最佳答案是利用2的次方必然是只有一个bit为1，那么取反+1之后进行与操作，还是与原数相同

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 1) {
            if (n % 2 != 0) return false;
            n >>= 1;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long x = n;
        return (x & (-x)) == x;
    }
};