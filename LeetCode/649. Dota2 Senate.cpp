class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        vector<int> ban(n, 0);
        int rCount = 0;
        int dCount = 0;
        int i = 0;
        int lastChange = 0;
        while(true) {
            if (lastChange == i) {
                if (rCount > 0) {
                    return "Radiant";
                }
                if (dCount > 0) {
                    return "Dire";
                }
            }
            if (ban[i] == 0) {
                if (senate[i] == 'R') {
                    if (dCount > 0) {
                        ban[i] = 1;
                        --dCount;
                        lastChange = i;
                    }
                    else {
                        rCount++;
                    }
                }
                else {
                    if (rCount > 0) {
                        ban[i] = 1;
                        --rCount;
                        lastChange = i;
                    }
                    else {
                        dCount++;
                    }
                }
            }
            i = (i + 1) % n;
        }

        return "Default";
    }
};