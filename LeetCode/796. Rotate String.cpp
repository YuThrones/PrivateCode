class Solution {
    public:
        bool rotateString(string s, string goal) {
            if (s.length() != goal.length()) {
                return false;
            }
            int size = s.size();
            int i = 0;
            while(i < size) {
                bool isOk = true;
                for (int j = 0; j < size; ++j) {
                    if (s[(i + j) % size] != goal[j]) {
                        isOk = false;
                        break;
                    }
                }
                if (isOk) {
                    return true;
                }
                ++i;
            }
            return false;
        }
    };