// 其实暴力的从大到小还原就行，因为翻转前面的不影响后面
// 后面的一个数复位只需要两次翻转，一次翻转到第一位，然后再翻到自己要的位置

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i = n - 1; i >= 0; --i) {
            if (arr[i] == i + 1) {
                continue;
            }
            int k = -1;
            for(int j = 0; j < i; ++j) {
                if (arr[j] == i + 1) {
                    k = j + 1;
                    break;
                }
            }
            ans.push_back(k);
            for (int j = 0; j < k / 2; ++j) {
                swap(arr[j], arr[k - 1 - j]);
            }
            for (int j = 0; j < (i + 1) / 2; ++j) {
                swap(arr[j], arr[i - j]);
            }
            ans.push_back(i + 1);
        }
        return ans;
    }
};