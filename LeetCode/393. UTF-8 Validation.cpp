#include<vector>
using namespace std;

class Solution {
    public:
        bool validUtf8(vector<int>& data) {
            int index = 0;
            vector<int> mask1{0b10000000};
            vector<int> mask2{0b11100000, 0b11000000};
            vector<int> mask3{0b11110000, 0b11000000, 0b11000000};
            vector<int> mask4{0b11111000, 0b11000000, 0b11000000, 0b11000000};
    
            vector<int> flag1{0b00000000};
            vector<int> flag2{0b11000000, 0b10000000};
            vector<int> flag3{0b11100000, 0b10000000, 0b10000000};
            vector<int> flag4{0b11110000, 0b10000000, 0b10000000, 0b10000000};
    
            while(index < data.size()) {
                if (isOk(data, index, mask1, flag1)) {
                    index += 1;
                    continue;
                }
                if (isOk(data, index, mask2, flag2)) {
                    index += 2;
                    continue;
                }
                if (isOk(data, index, mask3, flag3)) {
                    index += 3;
                    continue;
                }
                if (isOk(data, index, mask4, flag4)) {
                    index += 4;
                    continue;
                }
                return false;
            }
            return true;
        }
    
        bool isOk(vector<int>& data, int start, vector<int>& mask, vector<int>& flag) {
            // if (mask.size() != flag.size()) {return false;}
            int n = mask.size();
            if ((n + start) > data.size()) {return false;}
            for (int i = 0; i < n; ++i) {
                int index = i + start;
                if ((data[index] & mask[i]) != flag[i]) {return false;}
            }
            return true;
        }
    };


int main() {
    Solution s;
    vector<int> data = {197,130,1};
    auto res = s.validUtf8(data);
    return 0;
}