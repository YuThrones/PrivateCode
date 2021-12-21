// 本质是利用快排的partition，然后根据每个区间有多少人，算出要在哪个区间找到第k大的数，快排的partition写熟悉就行，判断好边界条件

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, k, 0, nums.size());
    }
    int find(vector<int>& nums, int k, int start, int end) {
        if (end - start <= 1) {
            return nums[start];
        }
        vector<int> mid = partition(nums, start, end);
        if (mid[1] + k <= end) {
            // 答案在右边部分
            return find(nums, k, mid[1], end);
        }
        else if (mid[0] + k < end and mid[1] + k > end) {
            // 落在中间部分，直接返回
            return nums[mid[1] - 1];
        }
        else {
            return find(nums, k - (end - mid[0] - 1), start, mid[0] + 1);
        }
    }
    
    vector<int> partition(vector<int>& nums, int start, int end) {
        vector<int> mid = vector<int>();
        mid.push_back(start - 1);
        mid.push_back(end);
        int random_index = rand() % (end - start - 1) + start;
        swap(nums[start], nums[random_index]);
        int key = nums[start];
        int index = start;
        while(index < mid[1] && mid[0] < mid[1]) {
            if (nums[index] < key) {
                swap(nums[index], nums[++mid[0]]);
            }
            else if (nums[index] > key) {
                swap(nums[index], nums[--mid[1]]);
            }
            else {
                ++index;
            }
        }
        return mid;
    }
    
    void print(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};