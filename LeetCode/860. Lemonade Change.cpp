class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            vector<int> count (21, 0);
            for (int i = 0; i < bills.size(); ++i) {
                if (bills[i] == 5) {
                    count[5]++;
                }
                else if (bills[i] == 10) {
                    if (count[5] > 0) {
                        --count[5];
                        ++count[10];
                    }
                    else {
                        return false;
                    }
                }
                else if (bills[i] == 20) {
                    if (count[10] > 0 && count[5] > 0) {
                        --count[10];
                        --count[5];
                        ++count[20];
                    }
                    else if (count[5] > 2) {
                        count[5] -= 3;
                        ++count[20];
                    }
                    else {
                        return false;
                    }
                }
            }
            return true;
        }
    };