class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            if(k != 0) {
                int dir = k > 0 ? 1 : -1;
                for(int j = dir; abs(j) <= abs(k); j += dir) {
                    sum += code[(i + j + n) % n];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};