// 这道题没想到优雅的实现来避免多个相加溢出的问题，最佳答案也是用long long 取巧

#define ll long long
ll t[100002];
ll p[100002];
int up, lo;

class Solution {
public:
    
    int ans = 0;
    void mergeSort(int l, int h) {
        if(l==h) return;
        
        int m = (h-l)/2 + l;
        
        mergeSort(l, m);
        mergeSort(m+1, h);
        
        int s = m+1, e=m+1;
        for(int i=l;i<=m;i++) {
            while(s<=h && p[s]-p[i] < lo) s++;
            while(e<=h && p[e]-p[i]<= up) e++;
            ans += (e-s);
        }
        merge(l, h);
    }
    
    void merge(int l, int h) {
        int m = (h-l)/2 + l;
        
        int i=l, j=m+1;
        int ind = 0;
        while(i<=m && j<=h) {
            if(p[i]<= p[j]) t[ind++] = p[i++];
            else t[ind++] = p[j++];
        }
        
        while(i<=m) t[ind++] = p[i++];
        while(j<=h) t[ind++] = p[j++];
        
        for(i=l;i<=h;i++) p[i] = t[i-l];
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lo = lower;
        up = upper;
        int n = nums.size();
        for(int i=0;i<n;i++) p[i+1] = p[i]+nums[i]; 
        
        ans =0;
        mergeSort(0, n);
        return ans;
    }
};