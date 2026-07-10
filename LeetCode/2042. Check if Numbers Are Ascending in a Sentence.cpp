class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream iss(s);
        string token;
        int last = -1;
        while (iss >> token) {
            bool bIsNum = true;
            for(auto c : token) {
                if (!isdigit(c)) {
                    bIsNum = false;
                    break;
                }
            }
            if (!bIsNum) {
                continue;
            }
            int temp = stoi(token);
            if (temp <= last) {
                return false;
            }
            last = temp;
        }
        return true;
    }
};