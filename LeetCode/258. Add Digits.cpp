// 题目很简单，记得内联提高效率就行

class Solution {
public:
    int addDigits(int num) {
        while(num > 9) num = cal(num);
        return num;
    }
    
    inline int cal(int num) {
        int count = 0;
        while(num > 0) {
            count += num % 10;
            num /= 10;
        }
        return count;
    }
};