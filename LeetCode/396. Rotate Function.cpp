// 这道题一开始理解错了，其实只需要想清楚一个问题，每次右移的时候，所有位置的数字都少了1份，只有最大的位置从0份变成了N份

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total=0;
        int placeTotal=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
            placeTotal+=(i*nums[i]);
        }
        
        int ans=placeTotal;
        for(int i=0;i<nums.size();i++)
        {
            placeTotal-=total;
            placeTotal+=nums[i];
            placeTotal+=(nums[i]*(nums.size()-1));
            ans=max(ans,placeTotal);
        }
        return ans;
        
    }
};