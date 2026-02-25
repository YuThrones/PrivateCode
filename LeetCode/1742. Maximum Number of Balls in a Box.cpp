class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> rec(9 * 5 + 1, 0);
        for(int i = lowLimit; i <= highLimit; ++i) {
            int sum = 0;
            int num = i;
            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }
            rec[sum] += 1;
        }
        int cnt = 0;
        for (int i = 1; i < rec.size(); ++i) {
            cnt = max(cnt, rec[i]);
        }
        return cnt;
    }
};