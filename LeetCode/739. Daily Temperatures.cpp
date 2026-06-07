// 最佳答案比我少用一个vector，利用ans原本存储的信息，跳转到下个位置更热的位置，只需要记录一个最热天，常数上要快一些

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            if (temperatures[i] >= hottest) {
                hottest = temperatures[i];
                continue;
            }
            int days = 1;
            while (temperatures[i + days] <= temperatures[i])
                days += ans[i + days];
            ans[i] = days;
        }
        return ans;
    }
    
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> future;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; --i) {
            int tem = temperatures[i];
            while(!future.empty() && future[future.size() - 1].first <= tem) {
                future.pop_back();
            }
            if(!future.empty()) {
                ans[i] = future[future.size() - 1].second - i;
            }
            future.push_back({tem, i});
        }
        return ans;
    }
};