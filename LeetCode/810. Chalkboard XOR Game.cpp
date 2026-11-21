// 这道题递归直接超时了，其实是有数学结论，没想到没办法了
// 先手只有异或和为0，或者数组是偶数的时候可以获胜

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int v : nums) {
            x ^= v;
        }
        return x == 0 || nums.size() % 2 == 0;
    }
};