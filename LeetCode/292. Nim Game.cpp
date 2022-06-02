// 这道题可以用递归，但是会超时，经典解法是打表，观察规律，不过其实也可以想到，每次拿1-3个，必然可以保证一轮两个人拿4个，对4求余数即可

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};