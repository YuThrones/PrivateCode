class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> rec(n + 1, vector<double>(k + 1, 0));
        return cal(nums, k, 0, rec);
    }

    double cal(vector<int>& nums, int k, int start, vector<vector<double>>& rec) {
        int n = nums.size();
        if(k == 0) {
            return 0;
        }
        if (start >= n) {
            return 0;
        }
        double ans = 0;
        if(rec[start][k] != 0) {
            return rec[start][k];
        }
        if (k == 1) {
            for(int i = start; i < n; ++i) {
                ans += nums[i];
            }
            rec[start][k] = ans / (n - start);
            return rec[start][k];
        }
        double acc = 0;
        for(int i = start; i < n; ++i) {
            acc += nums[i];
            ans = max(ans, acc / (i - start + 1) + cal(nums, k - 1, i + 1, rec));
        }
        rec[start][k] = ans;
        return rec[start][k];
    }
};