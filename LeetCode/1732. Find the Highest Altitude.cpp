class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int temp = 0;
        for(int g : gain) {
            temp += g;
            ans = max(temp, ans);
        }
        return ans;
    }
};