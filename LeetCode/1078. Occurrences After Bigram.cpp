class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        int cnt = 0;
        stringstream ss(text);
        string temp;
        while(ss >> temp) {
            if(cnt == 2) {
                ans.push_back(temp);
                if (first == second) {
                    cnt = 1;
                }
                else {
                    cnt = 0;
                }
            }

            if(temp == second && cnt == 1) {
                ++cnt;
            }
            else if(temp == first && cnt == 0) {
                ++cnt;
            }

            if (temp != first && temp != second) {
                cnt = 0;
            }
        }
        return ans;
    }
};