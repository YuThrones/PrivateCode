class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for(int i = 0; i < arr.size(); ++i) {
            bool stop = false;
            for (int j = 1; j < k; ++j) {
                for (int l = 0; l < m; ++l) {
                    int index = i + j * m + l;
                    if (index >= arr.size()) {
                        stop = true;
                        break;
                    }
                    if (arr[index] != arr[i + l]) {
                        stop = true;
                        break;
                    }
                }
                if (stop) {
                    break;
                }
            }
            if (!stop) {
                return true;
            }
        }
        return false;
    }
};