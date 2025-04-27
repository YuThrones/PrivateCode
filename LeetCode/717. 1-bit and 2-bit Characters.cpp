class Solution {
    public:
        bool isOneBitCharacter(vector<int>& bits) {
            bool isOne = false;
            int i = 0;
            for(; i < bits.size();) {
                if (bits[i] == 0) {
                    ++i;
                    isOne = true;
                }
                else {
                    isOne = false;
                    i += 2;
                }
            }
            return isOne;
        }
    };