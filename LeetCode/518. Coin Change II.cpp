class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount % 2 == 1) {
            bool bHasOdd = false;
            for (auto c : coins) {
                if (c % 2 == 1) {
                    bHasOdd = true;
                    break;
                }
            }
            if (!bHasOdd) {
                return 0;
            }
        }

        vector<int> result(amount + 1, 0);
        result[0] = 1;
        for (int j = 0; j < coins.size(); ++j) {
            int coin = coins[j];
            for(int i = coin; i <= amount; ++i) {
                result[i] += result[i - coin];
                // cout << i << " " << result[i] << endl;
            }
        }
        return result[amount];
    }
};