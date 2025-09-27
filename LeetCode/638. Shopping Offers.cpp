// 这道题直接递归就可以出答案，最佳答案是加了一个缓存，其他的思路是一样的

class Solution {
private:
    bool AllLess(vector<int>& special, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (special[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }
    int ApplySpecial(vector<int>& special, vector<int>& needs) {
        int total = 0;
        for (int i = 0; i < needs.size(); i++) {
            total += special[i];
            needs[i] -= special[i];
        }
        return total;
    }

    void UnApplySpecial(vector<int>& special, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] += special[i];
        }
    }
    int ShoppingOffersRecurse(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int required, map<vector<int>, int, less<vector<int>>>& dp) {
        if (required == 0) {
            return 0;
        }
        if (dp.find(needs) != dp.end()) {
            return dp[needs];
        }
        int n = price.size();
        int res = std::numeric_limits<int>::max();
        // Try the specials first.
        for (auto& special_item : special) {
            if (AllLess(special_item, needs)) {
                int total = ApplySpecial(special_item, needs);
                res = min(res, special_item[n] + ShoppingOffersRecurse(price, special, needs, required-total, dp));
                UnApplySpecial(special_item, needs);
            }
        }
        int total_cost = 0;
        // Try each item next.
        for (int i = 0; i < n; i++) {
            total_cost += needs[i]*price[i];
        }
        res = min(res, total_cost);
        dp[needs] = res;
        return res;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int required = 0;
        for (int need : needs) {
            required += need;
        }
        map<vector<int>, int, less<vector<int>>> dp;
        return ShoppingOffersRecurse(price, special, needs, required, dp);
    }
};

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return cal(price, special, needs, 0);
    }

    int cal(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int index) {
        int n = price.size();
        if (index >= special.size()) {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += price[i] * needs[i];
            }
            // cout << "last " << ans << endl;
            return ans;
        }
        int ret = cal(price, special, needs, index + 1);
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (special[index][j] > needs[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int j = 0; j < n; ++j) {
                needs[j] -= special[index][j];
            }
            int temp = cal(price, special, needs, index) + special[index][n];
            for (int j = 0; j < n; ++j) {
                needs[j] += special[index][j];
            }
            ret = min(temp, ret);
        }
        return ret;
    }
};