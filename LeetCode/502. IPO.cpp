// 这道题倒是一下子想出来了解法，按照可用门槛先排序，然后把对应收益放到最大堆，维持收入就行了，不过不够快
// 首先是最大堆好像只需要维持一个收益，不需要索引
// 其次最佳答案进行了一个大剪枝，如果一开始就可以满足所有的门槛，那直接选收益最高的前K个，这个可能对于这个题的测试数据收益很大

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> pq;
        int n = profits.size();
        vector<pair<int, int>> vec;
        vec.reserve(n);
        for(int i = 0; i < n; ++i) {
            vec.push_back({capital[i], i});
        }
        sort(vec.begin(), vec.end(), less<pair<int, int>>());
        int finish = 0;
        int check = 0;
        int cur = w;
        while(finish < k) {
            for(; check < n; ++check) {
                if(vec[check].first > cur) {
                    break;
                }
                pq.push({profits[vec[check].second], vec[check].second});
            }
            if(pq.empty()) {
                break;
            }
            pair<int, int> top = pq.top();
            pq.pop();
            cur += top.first;
            ++finish;
        }
        return cur;
    }
};

// 最佳答案
class Solution {
public:
    int findMaximizedCapital(int k, int w,
        vector<int>& profits, vector<int>& capital) {
        if (*std::max_element(capital.begin(), capital.end()) <= w) {
            std::nth_element(profits.begin(), profits.begin() + k,
                profits.end(), std::greater<>{});
            return std::accumulate(profits.begin(), profits.begin() + k, 0) + w;
        }
        std::vector<std::pair<int, int>> projects; // index
        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(std::pair{ capital[i], profits[i] });
        }
        std::ranges::sort(projects);

        std::priority_queue<int> q; // profit, capital
        int i = 0;
        int finished = 0;
        int cap = w;
        while (finished < k) {
            while (i < projects.size() && projects[i].first <= cap) {
                q.push(projects[i].second);
                ++i;
            }

            if (q.empty()) break;

            ++finished;
            cap += q.top();
            q.pop();
        }
        return cap;
    }
};