class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> count;
        int val = arr.size() / 4 + 1;
        for (int n : arr) {
            count[n]++;
            if (count[n] >= val) {
                return n;
            }
        }
        return 0;
    }
};