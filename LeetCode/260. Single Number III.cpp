// 第一反应肯定是用set或者map来做
// 但是更快肯定是用异或，先整个vector异或一遍，拿到异或和，然后找到异或和其中一个不为1的位（因为有两个数唯一，所以必定存在），利用这个位作为两个数的区别来进行区分，再进行一次异或，就可以找到第一个数
// 然后用第一次的异或和再异或一次，找到第二个数

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto const n: nums) x ^= n;
        
        int bit = 1;
        while(!(bit & x)) {
            bit <<= 1;
        }
        
        int y = 0;
        for (auto const n: nums) {
            if (n & bit) {
                y ^= n;
            }
        }
        
        vector<int> res;
        res.push_back(y);
        res.push_back(x ^ y);
        return res;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> se;
        for (auto n: nums) {
            if (se.find(n) != se.end()) se.erase(n);
            else se.insert(n);
        }
        vector<int> res;
        for (auto it: se) {
            res.push_back(it);
        }
        return res;
    }
};