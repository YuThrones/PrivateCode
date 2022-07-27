// 这道题原本我自己的想法是，用二分的方式找到当前位置往右的一个比自己小但是比自己后面都大的数，但是发现如果最后边是最大值，这个方法完全行不通，也就是不稳定
// 看了下讨论，其实这道题是可以用归并排序的方式来做的，用归并排序，从大到小排，当一个数组段，左半部分一个数被merge的时候，其实我们就可以肯定，这时候已经merge的右半部分比他大，而剩下部分一定比他小，于是我们可以记录右半部分剩余长度
// 也就是比他小的数，这样可以得出稳定的O(nlogn)复杂度
// 提交之后，发现这还不是最快的，最快答案非常的刁钻，是通过不断的加上一个数最末尾的1的位置代表的数，这样前面相同，但是最后位置大1的数，必然比自己大，记录这个位置小于等于他的数
// 当查询的时候，只需要反向减去最后一位，可以保证不会重复的加上所有比自己小的数，取巧，但是非常的巧妙，在范围不是很大的时候确实要更快，复杂度与区间挂钩

// 论坛答案
class Solution {
public:

    void merge(int left, int mid, int right, vector<pair<int, int>>& arr,vector<int>& count)
    {
        vector<pair<int, int>> temp(right - left + 1);
        
        int i = left;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= right)
        {
            if(arr[i].first <= arr[j].first)
            {
                temp[k++] = arr[j++]; 
            }
            else
            {
                count[arr[i].second] += (right - j + 1);
                
                temp[k++] = arr[i++];
            }
        }
        
        while(i <= mid)
        {
            temp[k++] = arr[i++];
        }
        
        while(j <= right)
        {
            temp[k++] = arr[j++];
        }
        
        for(int l = left; l <= right; l++)
        arr[l] = temp[l - left];
        
    }
                
    void mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int>& count)
    {
        if(left >= right)
        {
            return;
        }

        int mid = left + (right - left) / 2;
        
        mergeSort(left, mid, arr, count);
        mergeSort(mid + 1, right, arr, count);
        
        merge(left, mid, right, arr, count);
    }
    
	vector<int> countSmaller(vector<int>& nums) {
	    
        int n=nums.size();
	    vector<pair<int, int>> arr;
        
	    for(int i = 0; i < n; i++)
	    {
	        arr.push_back({nums[i], i});
	    }
	    
	    vector<int> count(n, 0);
	    
	    mergeSort(0, n - 1, arr, count);
	    
	    return count;
	}
  
};


// 最佳答案
class Solution {
public:
    int n, sum[20004];
    inline void add(int x){
        while(x<=n){
            sum[x]++;
            x+= (x&-x);
        }
        return;
    }
    inline int query(int x){
        int ret= 0;
        while(x){
            ret+= sum[x];
            x-= (x&-x);
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n= 20001;
        memset(sum, 0, sizeof sum);
        int sz= nums.size();
        vector<int>ret(sz, 0);
        for(int i=sz-1; i>=0; i--){
            int x= nums[i]+10001;
            add(x);
            ret[i]= query(x-1);
        }
        return ret;
    }
};