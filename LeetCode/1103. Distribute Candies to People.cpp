class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0;
        while(candies > 0) {
            // cout << i << " " << ans[i % num_people] << endl;
            int temp = min(candies, i + 1);
            ans[i % num_people] += temp;
            candies -= temp;
            ++i;
        }
        return ans;
    }
};