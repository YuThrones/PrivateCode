class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto& l : logs) {
            if (l == "../") {
                if (ans > 0) {
                    --ans;
                }
            }
            else if (l == "./") {
                continue;
            }
            else {
                ++ans;
            }
        }
        return ans;
    }
};