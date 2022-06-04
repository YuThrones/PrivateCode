# 记录当前位置为终点的最长上升序列结果，然后用前面的结果加速计算，虽然可以通过，但是速度不够
# 看了下最快答案，采取的方法是用一个vector记录当前的序列，如果比他大就往后加，如果比他小，就找到第一个比他大的数并且替换，这样保证了后半部分如果出现了新的序列不会漏掉

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // int dp[n];
        // dp[0] = 1;
        // int ans = 1;
        // for(int i=1; i<n; i++){
        //     int mx = 0;
        //     for(int j=0; j<i; j++){
        //         if(nums[j] < nums[i]){
        //             mx = max(mx, dp[j]);
        //         }
        //     }
        //     dp[i] = mx+1;
        //     ans = max(ans, mx+1);
        // }
        // return ans;
        
//         Using Binary Search: O(N*LogN):
        
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        vector<int> record(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    record[i] = max(record[i], record[j] + 1);
                }
                res = max(res, record[i]);
            }
        }
        return res;
    }
};