class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> arr;
        for (auto& p : points) {
            arr.push_back(p[0]);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            cout << arr[i] << " " << arr[i + 1] << endl;
            if (arr[i + 1] - arr[i] > 0) {
                ans = max(ans, arr[i + 1] - arr[i]);
            }
        }
        return ans;
    }
};