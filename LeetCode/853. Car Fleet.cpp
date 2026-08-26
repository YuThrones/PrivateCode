class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        int ans = 0;
        long long lastNum = -1;   // 分子，代表前面领头车的到达时间
        long long lastDen = 1;    // 分母

        // 从离 target 最近的车开始往远遍历
        for (int i = n - 1; i >= 0; i--) {
            long long curNum = target - cars[i].first;
            long long curDen = cars[i].second;

            // 判断 curNum/curDen > lastNum/lastDen ?
            if (curNum * lastDen > lastNum * curDen) {
                ans++;
                lastNum = curNum;
                lastDen = curDen;
            }
            // 否则追上了，什么也不做（并入前面车队）
        }
        return ans;
    }
};