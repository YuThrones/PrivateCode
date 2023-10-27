// 这道是纯数学题，能想到是要利用编码，但是没有想清楚思路
// 参考 https://blog.csdn.net/qq_46105170/article/details/104112252 的思路写
// 一开始我的想法是死活代表0或者1，但是发现完全不对，是要根据第几次死来确定某个进位的数字，attempts才是进制

#include<cmath>

#include <cmath>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempts = minutesToTest / minutesToDie + 1;
        int count = 0;
        int n = buckets - 1;
        while(n > 0) {
            ++count;
            n /= attempts;
        }
        return count;
    }
};


int main() {
    int buckets = 1000;
    int minutesToDie = 15;
    int minutesToTest = 60;
    Solution sol;
    int res = sol.poorPigs(buckets, minutesToDie, minutesToTest);
    return 0;
}