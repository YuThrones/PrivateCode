// 只想到了排序再解，比最佳答案二分慢太多了
// 最佳答案思路是因为是分数，所以一定在0-1之间，只需要统计某个区间有多少个数就行，不需要知道具体是谁，通过这种方式减少计算

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;

        while (true) {
            double mid = (low + high) / 2.0;

            int count = 0;
            int p = 0, q = 1;
            int j = 1;

            for (int i = 0; i < n - 1; i++) {
                while (j < n && arr[i] > mid * arr[j])
                    j++;

                if (j == n) break;

                count += (n - j);

                if ((long long)arr[i] * q > (long long)p * arr[j]) {
                    p = arr[i];
                    q = arr[j];
                }
            }

            if (count == k)
                return {p, q};
            else if (count < k)
                low = mid;
            else
                high = mid;
        }
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> sa;
        for(int i = 0; i < arr.size() - 1; ++i) {
            for(int j = i + 1; j < arr.size(); ++j) {
                sa.push_back({arr[i], arr[j]});
            }
        }
        sort(sa.begin(), sa.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first * b.second < a.second * b.first;
        });
        return vector<int> {sa[k - 1].first, sa[k - 1].second};
    }
};