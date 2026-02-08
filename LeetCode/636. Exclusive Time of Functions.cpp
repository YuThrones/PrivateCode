class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        vector<pair<int, int>> startTime;
        for (string& log :logs) {
            int first = log.find(':');
            int second = log.find(':', first + 1);
            int id = stoi(log.substr(0, first));
            int time = stoi(log.substr(second + 1, log.length() - second - 1));

            if (log.substr(first + 1, second - first - 1) == "start") {
                if (startTime.size() > 0) {
                    pair<int, int> lastPair = startTime.back();
                    ans[lastPair.first] += (time - lastPair.second);
                }
                startTime.push_back({id, time});
            }
            else {
                pair<int, int> lastPair = startTime.back();
                startTime.pop_back();
                ans[lastPair.first] += (time - lastPair.second + 1);

                if (startTime.size() > 0) {
                    startTime.back().second = time + 1;
                }
            }
        }
        return ans;
    }
};