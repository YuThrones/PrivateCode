class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> rec(edges.size() + 2, 0);
        for(auto& e: edges) {
            rec[e[0]]++;
            rec[e[1]]++;
        }
        int n = rec.size();
        for(int i = 0; i < n; ++i) {
            if(rec[i] > 1) {
                return i;
            }
        }
        return 0;
    }
};