class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (check(p1, p2, p3 ,p4)) {
            return true;
        }
        if (check(p1, p3, p2, p4)) {
            return true;
        }
        if (check(p1, p3, p4, p2)) {
            return true;
        }
        return false;
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> line1{p2[0] - p1[0], p2[1] - p1[1]};
        vector<int> line2{p3[0] - p2[0], p3[1] - p2[1]};
        vector<int> line3{p4[0] - p3[0], p4[1] - p3[1]};
        vector<int> line4{p1[0] - p4[0], p1[1] - p4[1]};

        if (line1[0] == 0 && line1[1] == 0) {
            return false;
        }

        if (line1[0] * line1[0] + line1[1] * line1[1] != line2[0] * line2[0] + line2[1] * line2[1]) {
            return false;
        }

        if (line1[0] * line1[0] + line1[1] * line1[1] != line3[0] * line3[0] + line3[1] * line3[1]) {
            return false;
        }

        if (line1[0] * line1[0] + line1[1] * line1[1] != line4[0] * line4[0] + line4[1] * line4[1]) {
            return false;
        }

        if (!((line1[0] * line2[0] + line1[1] * line2[1]) == 0
        && (line2[0] * line3[0] + line2[1] * line3[1]) == 0
        && (line3[0] * line4[0] + line3[1] * line4[1]) == 0)) {
            return false;
        }

        return true;
    }
};