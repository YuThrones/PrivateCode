class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.size() == 0) {
            return 0;
        }
        int ans = 0;
        int largest = -1;
        for(int i = 0; i < arr.size(); ++i) {
            largest = max(largest, arr[i]);
            if (largest == i) {
                ++ans;
                largest = -1;
            }
        }
        return ans;
    }
};