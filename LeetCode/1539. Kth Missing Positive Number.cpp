class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last = 0;
        int count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            while (arr[i] - last > 1) {
                ++count;
                ++last;
                if (count == k) {
                    return last;
                }
            }
            last = arr[i];
        }
        return last + k - count;
    }
};