// 除法转乘法，避免小数问题就好

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 2) {
            return true;
        }
        vector<int>& a = coordinates[0];
        vector<int>& b = coordinates[1];
        for (int i = 2; i < coordinates.size(); ++i) {
            vector<int>& c = coordinates[i];
            if ((b[1] - a[1]) * (c[0] - a[0]) != (c[1] - a[1]) * (b[0] - a[0])) {
                return false;
            }
        }
        return true;
    }
};