最佳答案应该是打表得出规律的，O(1)。太快了

class Solution {
public:
    bool divisorGame(int n) {
        if(n%2==0)
            return true;
        
        return false;
    }
};

class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> record(n + 1, false);
        record[0] = false;
        record[1] = false;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if ((i % j == 0) && !record[i - j]) {
                    record[i] = true;
                    break;
                }
            }
        }
        return record[n];
    }
};