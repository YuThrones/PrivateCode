class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (auto s : timePoints) {
            int hour = stoi(s.substr(0, 2));
            int min = stoi(s.substr(3, 2));
            times.push_back(hour * 60 + min);
            times.push_back(hour * 60 + min + 24 * 60);
        }
        sort(times.begin(), times.end());
        int result = INT_MAX;
        for (int i = 1; i < times.size(); ++i) {
            result = min(result, times[i] - times[i - 1]);
        }
        return result;
    }
};