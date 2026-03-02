class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1;
        int dist = INT_MAX;
        for(int i = 0; i < points.size(); ++i) {
            vector<int>& p = points[i];
            if (p[0] == x) {
                if(abs(p[1] - y) < dist) {
                    dist = abs(p[1] - y);
                    index = i;
                    
                }
            }
            else if(p[1] == y) {
                if(abs(p[0] - x) < dist) {
                    dist = abs(p[0] - x);
                    index = i;
                }
            }
        }
        return index;
    }
};