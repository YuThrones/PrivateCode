class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> record;
        unordered_map<int, int> count;
        for (auto n : arr) {
            count[n]++;
        }
        for (auto& it : count) {
            if (record.find(it.second) != record.end()) {
                return false;
            }
            record.insert(it.second);
        }

        return true;
    }
};