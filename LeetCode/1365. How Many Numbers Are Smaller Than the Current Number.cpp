// 跟最佳答案的区别在于我是单独存了所以在一个表里，原数组排序之后查表，最佳答案是把下标和值放一起排序，省了查表时间，不过排序应该慢一点。
// 从结果看总体更快，思路没有区别。

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> ans (nums.size());
        int k=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans[v[i].second]=0;
            }
            else if(i>0 && v[i].first==v[i-1].first)
            {
                l+=1;
                ans[v[i].second]=k;
            }
            else{
                l+=1;
            ans[v[i].second]=l;
                k=l;
            }
        }
    
    return ans;
        }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        unordered_map<int, vector<int>> record;
        for (int i = 0; i < nums.size(); ++i) {
            record[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        int last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (last != nums[i]) {
                for (int j = 0; j < record[nums[i]].size(); ++j) {
                    ans[record[nums[i]][j]] = i;
                }
                last = nums[i];
            }
        }
        return ans;
    }
};