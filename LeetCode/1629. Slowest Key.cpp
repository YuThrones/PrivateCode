class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int maxVal = releaseTimes[0];
        for (int i = 1; i < keysPressed.length(); ++i) {
            int Val = releaseTimes[i] - releaseTimes[i - 1];
            if (Val > maxVal) {
                maxVal = Val;
                ans = keysPressed[i];
            }
            else if (Val == maxVal && keysPressed[i] > ans) {
                ans = keysPressed[i];
            }

        }
        return ans;
    }
};