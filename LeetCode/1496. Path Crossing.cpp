class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> record;

        pair<int, int> pos {0, 0};
        record.insert(pos);
        for (auto c : path) {
            if (c == 'N') {
                pos.second += 1;
            }
            else if (c == 'S') {
                pos.second -= 1;
            }
            else if (c == 'W') {
                pos.first -= 1;
            }
            else if (c == 'E') {
                pos.first += 1;
            }
            // cout << pos.first << " " << pos.second << endl;
            if (record.find(pos) != record.end()) {
                return true;
            }
            record.insert(pos);
        }
        return false;
    }
};