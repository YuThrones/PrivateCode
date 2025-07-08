class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int dif = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); ++i) {
            dif = min(dif, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> result;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] == dif) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};