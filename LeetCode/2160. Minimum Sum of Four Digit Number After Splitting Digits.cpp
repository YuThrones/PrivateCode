class Solution {
public:
    int minimumSum(int num) {
        vector<int> store;
        for(int i = 0; i < 4; ++i) {
            store.push_back(num % 10);
            num /= 10;
        }
        sort(store.begin(), store.end());
        return (store[0] * 10 + store[3]) + (store[1] * 10 + store[2]);
    }
};