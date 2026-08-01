class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if (isValid(i)) {
                ++ans;
            }
        }

        return ans;
    }

    bool isValid(int n) {
        vector<int> rot{0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        bool bFound = false;
        while(n > 0) {
            int temp = n % 10;
            if(rot[temp] < 0) {
                return false;
            }
            if (rot[temp] != temp) {
                bFound = true;
            }
            n /= 10;
        }
        if (!bFound) {
            return false;
        }
        return true;
    }
};