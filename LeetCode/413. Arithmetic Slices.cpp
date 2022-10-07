// 一开始想用动态规划，转念一想其实没这么复杂，只需要找到每一段连续大于3的数组，然后就可以直接算出这一段能划分不同长度的数量
// 不过我写的太复杂了，最佳答案比我简洁很多

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        cout << nums.size() <<endl;
        vector<pair<int, int>> rec;
        int start = 0;
        int interval = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (i - start == 1) {
                interval = nums[i] - nums[start];
            }
            else {
                if (nums[i] - nums[i - 1] != interval) {

                    if (i - start >= 3) {
                        rec.push_back(make_pair(start, i - 1));                    
                    }
                    start = i - 1;
                    interval = nums[i] - nums[i - 1];
                }
            }
        }
        
        if (nums.size() - start >= 3) {
            rec.push_back(make_pair(start, nums.size() - 1));
        } 
        
        int res = 0;
        for (auto it: rec) {
            int n = it.second - it.first + 1;
            for (int j = 3; j <= n; ++j) {
                res += n - j + 1;
            }
        }
        return res;
    }
    
};

// 最佳答案
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2)return 0;
        int count = 0, ans = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i+1] - nums[i] == nums[i+2] - nums[i+1]){
                count++;
            }
            else{
                ans += ((count * (count+1)) / 2);
                count = 0;
            }
            
        }
        if(count) ans += ((count * (count+1)) / 2);
        return ans;
    }
};