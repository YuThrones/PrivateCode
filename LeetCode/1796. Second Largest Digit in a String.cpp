class Solution {
public:
    int secondHighest(string s) {
        vector<int> vec;
        for(auto c : s) {
            if (c >= '0' && c <= '9') {
                int n = c - '0';
                if (find(vec.begin(), vec.end(), n) != vec.end()) {
                    continue;
                }
                vec.push_back(n);
                sort(vec.begin(), vec.end(), greater<int>());
                if (vec.size() > 2) {
                    vec.pop_back();
                }
            }
        }
        if (vec.size() < 2) {return -1;}
        return vec[1];
    }
};