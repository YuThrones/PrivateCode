这道题没读懂，直接去看了答案，感觉题目是有歧义的，字符串可以由自己生成，但是又截断了，
感觉长度为1的时候字符串是1还是2感觉都可以，没太理解

class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;

        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(2);

        int x = 1, num = 2, p = 2, i = 3, ans = 1;
        while (i < n) {
            for (int j = 0; j < num; j++)
                vec.push_back(x);

            if (x == 1)
                ans += min(num, n - i);

            x = 3 - x;
            i += num;
            num = vec[++p];
        }

        return ans;
    }
};