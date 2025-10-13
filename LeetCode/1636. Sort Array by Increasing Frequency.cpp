class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> fre;
        for(int n : nums) {
            ++fre[n];
        }
        vector<pair<int, int>> temp;
        for (auto it : fre) {
            temp.push_back({it.first, it.second});
        }
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b){
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        vector<int> res;
        for (auto& p : temp) {
            for (int i = 0; i < p.second; ++i) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};