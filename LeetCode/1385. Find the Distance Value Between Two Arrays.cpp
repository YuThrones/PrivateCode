class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int a1 : arr1) {
            bool isOk = true;
            for (int a2 : arr2) {
                if (abs(a1 - a2) <= d) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                ++ans;
            }
        }
        return ans;
    }
};