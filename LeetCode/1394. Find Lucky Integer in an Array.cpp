class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> record;
        for (int n : arr) {
            record[n]++;
        }
        int result = -1;
        for (int n : arr) {
            if (record[n] == n && n > result) {
                result = n;
            }
        }
        return result;
    }
};