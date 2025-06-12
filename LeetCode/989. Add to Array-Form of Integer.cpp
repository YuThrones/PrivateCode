class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int add = 0;
        int i = 0;
        while(k > 0 || add > 0) {
            if (i >= num.size()) {
                num.push_back(0);
            }
            num[i] += (k % 10) + add;
            k /= 10;
            add = num[i] / 10;
            num[i] %= 10;
            ++i;
        }
        if (add > 0) {
            num.push_back(add);
        }
        reverse(num.begin(), num.end());
        return num;
    }
};