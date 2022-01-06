// 最开始是用一个最小堆做的，把1放进去作为初始值，每次拿堆顶，然后分别乘以2、3、5之后放进堆中，但是事实证明这样不行，因为乘以2的时候可能没问题，乘以3或者5就溢出了
// 没想出来，看了下答案，其实三个变量就可以搞定，思想其实是用三个变量来维护类似最小堆的概念，确实挺精妙的
class Solution {
public:
    int nthUglyNumber(int n) {
        //dp - O(n) time, O(1) space
        
        int next2 = 0, next3 = 0, next5 = 0;
        int cur = 1, i = 1;
        int k[n];
        k[0] = 1;
        while(i < n) {
            cur = min(2*k[next2], min(3*k[next3], 5*k[next5]));
            if(cur == k[next2]*2) next2++;
            if(cur == k[next3]*3) next3++;
            if(cur == k[next5]*5) next5++;
            k[i] = cur;
            ++i;
        }
        return cur;
    }
};