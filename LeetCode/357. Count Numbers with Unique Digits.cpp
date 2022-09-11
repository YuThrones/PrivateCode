// 简单递归解决问题，数据量太小，甚至乜有动态规划的需要

#include<iostream>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        return cal(n);
    }
    
    int cal(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        
        int ans = 9;
        
        int temp = n - 1;
        int mul = 9;
        while(temp > 0 && mul >= 0) {
            ans *= mul;
            --mul;
            --temp;
        }
        
        return cal(n - 1) + ans;
    }
};


int main() {
    Solution s;
    int ans = s.countNumbersWithUniqueDigits(2);
    return 0;
}