// 虽然做出来了，但是写的不够简洁，而且常数时间上有点差距，可能是if嵌套太多了

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        int lastfruit = -1, secondlastfruit = -1;
        int currcount = 0, lastfruitstreak = 0;
        for(int fruit : fruits) {
            if(fruit == lastfruit || fruit == secondlastfruit) ++currcount;
            else currcount = lastfruitstreak + 1;
            if(fruit == lastfruit) ++lastfruitstreak;
            else {
                lastfruitstreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }
            maxLen = max(maxLen, currcount);
        }
        return maxLen;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int first = 0;
        int second = -1;
        int n = fruits.size();
        int lf = 0;
        int ls = -1;
        for(int i = 1; i < n; ++i) {
            if (fruits[i] != fruits[first]) {
                if(second < 0) {
                    second = i;
                    ls = i;
                }
                else {
                    if (fruits[i] != fruits[second]) {
                        ans = max(ans, i - first);
                        if(lf < ls) {
                            first = lf + 1;
                            lf = ls;
                        }
                        else {
                            first = ls + 1;
                        }
                        second = i;
                        ls = i;
                    }
                    else {
                        ls = i;
                    }
                }
            }
            else {
                lf = i;
            }
        }
        ans = max(ans, n - first);
        return ans;
    }
};