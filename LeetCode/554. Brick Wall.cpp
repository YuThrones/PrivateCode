class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, long long> record;
        int line = 0;
        for (vector<int>& row : wall) {
            long long sum = 0;
            for (int i = 0; i < row.size(); ++i) {
                sum += row[i];
                record[sum] += 1;
                // cout << i << ":" << row[i] << " ";
                if (i == row.size() - 1) {
                    line = sum;
                }
            }
            // cout << endl;
        }

        if (record.size() == 1) {
            return wall.size();
        }

        int num = INT_MIN;
        for (auto it : record) {
            // cout << it.first << ":" << it.second << endl;
            if (it.first == line) {
                continue;
            }
            if (it.second > num) {
                num = it.second;
            }
        }
        return wall.size() - num;
    }
};