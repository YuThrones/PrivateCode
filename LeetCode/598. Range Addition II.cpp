class Solution {
    public:
        int maxCount(int m, int n, vector<vector<int>>& ops) {
            int maxM = m;
            int maxN = n;
            for (auto& op : ops) {
                maxM = min(maxM, op[0]);
                maxN = min(maxN, op[1]);
            }
            return maxM * maxN;
        }
    };