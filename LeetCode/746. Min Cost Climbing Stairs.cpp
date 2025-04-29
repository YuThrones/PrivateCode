class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            if (cost.size() < 2) {return 1;}
            int prepre = 0;
            int pre = 0;
            for (int i = 2; i <= cost.size(); ++i) {
                int temp = min(pre + cost[i - 1], prepre + cost[i - 2]);
                prepre = pre;
                pre = temp;
            }
            return pre;
        }
    };