class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int i = 1;
        int sum = 0;
        while(sum < target || (sum - target) % 2 != 0) {
            sum += i;
            i++;
        }
        return i - 1;
    }
};