class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        for (int i = 0; i < n; ++i) {
            if (abs(arr[l] - x) > abs(arr[i] - x)) {
                l = i;
            }
        }
        r = l;
        // cout << l << " " << r << endl;
        
        while(r - l < k - 1) {
            if (l == 0) {
                r = k - 1;
                break;
            }
            else if(r == n - 1) {
                l = r - k + 1;
                break;
            }
            if (abs(arr[l - 1] - x) <= abs(arr[r + 1] - x)) {
                --l;
            }
            else {
                ++r;
            }
        }
        // cout << l << " " << r << endl;

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};