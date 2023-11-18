// 注意边界条件，也就是1和num本身就行

class Solution {
public:
    bool checkPerfectNumber(int num) {
        unordered_set<int> rec;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                rec.insert(i);
                rec.insert(num / i);
            };
        }
        int res = 1;
        for (auto i: rec) res += i;
        return res == num && num != 1;
    }
};