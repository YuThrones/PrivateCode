// 自己的做法直接塞一个循环了，似乎没有更快，反而变复杂了，不如拆两个循环简洁

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start,
                                int destination) {
        int n = distance.size(), sum = 0, df = 0;
        for (const int& d : distance)
            sum += d;

        for (int i = min(start, destination); i < max(start, destination); i++)
            df += distance[i];
        return min(df, sum - df);
    }
};

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = 0;
        int sum = 0;
        int n = distance.size();
        bool end = false;
        for (int i = 0; i < n; ++i) {
            total += distance[i];

            if ((start + i) % n == destination) {
                end = true;
            }
            if (!end) {
                sum += distance[(start + i) % n];
            }
        }
        return min(sum, total - sum);
    }
};