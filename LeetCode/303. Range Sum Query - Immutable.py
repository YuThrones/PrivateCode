# 提前算出每个终止位置累积和即可

class NumArray {
public:
    vector<int> sumCal;
    NumArray(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            sumCal.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        if (left <= 0) return sumCal[right];
        return sumCal[right] - sumCal[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */