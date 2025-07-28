class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        int result = INT_MIN;
        for (auto& arr : arrays) {
            if (maxValue != INT_MIN) {
                result = max(result, abs(maxValue - arr[0]));
                result = max(result, abs(arr[arr.size() - 1] - minValue));
            }
            minValue = min(arr[0], minValue);
            maxValue = max(arr[arr.size() - 1], maxValue);
        }
        return result;
    }
};