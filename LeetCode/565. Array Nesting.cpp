// 最佳答案直接用vector<int>记录是否访问，速度上更快

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int maxSize = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = 0;
                int cur = i;
                while (!visited[cur]) {
                    visited[cur] = true;
                    cur = nums[cur];
                    size++;
                }
                maxSize = max(maxSize, size);
            }
        }
        
        return maxSize;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> used;
        for (int i = 0; i < nums.size(); ++i) {
            used.empty();
            int count = 0;
            int last = i;
            while(used.find(last) == used.end()) {
                ++count;
                used.insert(last);
                last = nums[last];
            }
            ans = max(ans, count);
        }
        return ans;
    }
};