// 这道题有两个关键，第一个是把0转成-1，这样就是问题转化成找到一段和为0的连续子数组，
// 第二个是用vector模仿哈希表，记录下买个前缀和第一次出现的下标，只要找到相同下标就意味着找到一个答案

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, ans = 0, n = nums.size();
        vector<int> arr(2 * n + 1, INT_MIN);
        arr[n] = -1;
        for(int i = 0; i < n; i++){
            sum += (nums[i] == 1) ? 1 : -1;
            if(arr[sum + n] >= -1){
                ans = max(ans, i - arr[sum + n]);
            } else{
                arr[sum + n] = i;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;
        int sum = 0;
        int result = 0;
        for (int i = 0; i <nums.size(); ++i) {
            if (nums[i] == 0) {
                sum -= 1;
            }
            else {
                sum += 1;
            }
            if (prefixMap.find(sum) == prefixMap.end()) {
                prefixMap[sum] = i;
            }
            else {
                // cout << sum << " " << i << " " << prefixMap[sum] << endl;
                result = max(result, i - prefixMap[sum]);
            }
        }
        return result;
    }
};