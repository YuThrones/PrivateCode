class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> record(1000, 0);
        for(int a : answers) {
            record[a]++;
        }
        int ans = 0;
        for(int i = 0; i < 1000; ++i) {
            ans += ((record[i] + i) / (i + 1)) * (i + 1);
        }
        return ans;
    }
};