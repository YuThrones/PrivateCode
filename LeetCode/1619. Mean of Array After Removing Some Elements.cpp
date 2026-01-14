class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double cnt = 0;
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            if (0.05 * n > i || 0.95 * n <= i) {
                continue;
            }
            cnt += 1;
            sum += arr[i];
        }
        return sum / cnt;
    }
};