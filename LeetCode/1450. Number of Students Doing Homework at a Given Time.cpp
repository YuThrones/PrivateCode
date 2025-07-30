class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        int size = min(startTime.size(), endTime.size());
        for (int i = 0; i < size; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++ans;
            }
        }
        return ans;
    }
};