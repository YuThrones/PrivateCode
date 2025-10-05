最佳答案需要剪枝，先确定第三个数，然后尝试第二个数，并且找到所有满足的第一个数，用剪枝加速

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int right = 2; right < nums.size(); right++){ // left - mid - right
            int left = 0, mid = right-1;
            while(left < mid){
                if(nums[left] + nums[mid] > nums[right]){ // try a smaller sum
                    cnt += mid - left; // add all element left~mid-1
                    mid--; 
                }
                else{ // try a bigger sum
                    left++;
                }
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                    if (nums[i] + nums[j] <= nums[k]) {
                        break;
                    }
                    ++ans;
                }
            }
        }
        return ans;
    }
};