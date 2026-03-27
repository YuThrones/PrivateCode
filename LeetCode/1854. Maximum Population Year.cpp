class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> birth(2100, 0);
        vector<int> death(2100, 0);
        for (auto& pair: logs) {
            birth[pair[0]]++;
            death[pair[1]]++;
        }
        int count = 0;
        int ans = 0;
        int num = 0;
        for (int i = 1900; i < 2100; ++i) {
            count += birth[i] - death[i];
            if (count > num) {
                ans = i;
                num = count;
            }
        }
        return ans;
    }
};