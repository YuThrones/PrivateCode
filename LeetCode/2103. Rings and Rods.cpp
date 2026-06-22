class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> rec(10, vector<int>(3, 0));
        int n = rings.size() / 2;
        for(int i =  0; i < n; ++i) {
            int color;
            if (rings[i * 2] == 'R') {
                color = 0;
            }
            else if (rings[i * 2] == 'G') {
                color = 1;
            }
            else if (rings[i * 2] == 'B') {
                color = 2;
            }
            int index = rings[i * 2 + 1] - '0';
            rec[index][color] = 1;
        }
        int ans = 0;
        for(int i = 0; i < 10; ++i) {
            if (rec[i][0] > 0 && rec[i][1] > 0 && rec[i][2] > 0 ) {
                ++ans;
            }
        }
        return ans;
    }
};