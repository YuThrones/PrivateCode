class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        int maxNum = 0;
        for(auto n : nums) {
            count[n]++;
            maxNum = max(maxNum, n);
        }

        vector<int> record(maxNum + 1, 0);
        record[1] = count[1];
        for(int i = 2; i <= maxNum; ++i) {
            record[i] = max(record[i - 1], record[i - 2] + count[i] * i);
        }

        return record[maxNum];
    }
};