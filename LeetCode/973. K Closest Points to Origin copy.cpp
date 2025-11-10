// 想复杂了，直接看首尾两个，确定下最后一圈有多少个多余的就行

class Solution
{
public:
    std::vector<int> mostVisited(int n, std::vector<int> &rounds)
    {
        std::vector<int> res;
        auto start = rounds.front();
        auto end = rounds.back();
        if (start <= end)
        {
            for (int i = start; i <= end; ++i)
                res.push_back(i);
        }
        else
        {
            for (int i = 1; i <= end; ++i)
                res.push_back(i);
            for (int i = start; i <= n; ++i)
                res.push_back(i);
        
        }
        return res;
    }
};

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> count(n + 1, 0);
        for(int i = 0; i < rounds.size() - 1; ++i) {
            for(int j = rounds[i];;) {
                ++count[j];
                ++j;
                if(j > n) {
                    j -= n;
                }
                if (j == rounds[i + 1]) {
                    break;
                }
            }
        }
        ++count[rounds[rounds.size() - 1]];
        int highest = 0;
        for(int i = 1; i <= n; ++i) {
            highest = max(highest, count[i]);
            // cout << i << " " << count[i] << endl;
        }
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            if(count[i] == highest) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};