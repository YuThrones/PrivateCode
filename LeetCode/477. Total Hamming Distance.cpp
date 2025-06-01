class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> count1(65, 0);
        vector<int> count2(65, 0);
        for (int n : nums) {
            int bit = 0;
            while(bit < 64) {
                if (n & 1) {
                    count1[bit]++;
                }
                else {
                    count2[bit]++;
                }
                bit += 1;
                n >>= 1;
            }
        }
        int result = 0;
        for (int i = 0; i < count1.size(); ++i) {
            // cout << count1[i] << " " << count2[i] << endl;
            result += count1[i] * count2[i];
        }
        return result;
    }
};