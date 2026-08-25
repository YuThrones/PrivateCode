class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int, int> rec;
        for(int n : hand) {
            rec[n]++;
        }

        for(int n : hand) {
            if(rec[n] == 0) {
                continue;
            }
            for(int i = 0; i < groupSize; ++i) {
                if(rec[n + i] <= 0) {
                    return false;
                }
                --rec[n + i];
            }
        }
        
        return true;
    }
};