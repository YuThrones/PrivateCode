class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0);
        for (auto s : students) {
            ++count[s];
        }
        for (int i = 0; i < sandwiches.size(); ++i) {
            if (count[sandwiches[i]] <= 0) {
                return count[0] + count[1];        
            }
            --count[sandwiches[i]];
        }
        return count[0] + count[1];
    }
};