class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int valid = 0;
            int i = 0;
            while (i < flowerbed.size()) {
                if (flowerbed[i] == 1) {
                    i += 2;
                }
                else if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                    ++valid;
                    i += 2;
                }
                else {
                    ++i;
                }
            }
            return valid >= n;
        }
    };