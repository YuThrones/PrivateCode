class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> sum;
        sum.push_back(0);
        int ans = 0;
        int temp = 0;
        for(int a : arr) {
            temp += a;
            sum.push_back(temp);
        }
        for(int i = 1; i  <= arr.size(); i += 2) {
            for(int j = 0; j + i <= arr.size(); ++j) {
                ans += (sum[i + j] - sum[j]);
                // cout << (sum[i + j] - sum[j]) << endl;
            }
        }
        return ans;
    }
};