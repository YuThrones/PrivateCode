class Solution {
public:
    int kthGrammar(int n, int k) {
        return cal(k - 1);
    }

    int cal(int k) {
        if (k == 0) {
            return 0;
        }
        if (k % 2 == 0) {
            return cal(k / 2);
        }
        return 1 - cal(k / 2);
    }
};