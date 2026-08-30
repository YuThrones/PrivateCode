// 跟最佳答案比，我的排序显得要慢一些，在一定范围内基数排序更快

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> freq(limit + 1, 0);
        for(int cnt : people) {
            freq[cnt]++;
        }
        int idx = 0;
        for(int i = 0; i <= limit; i++) {
            while(freq[i] > 0) {
                people[idx] = i;
                freq[i]--;
                idx++;
            }
        }
        int start = 0;
        int end = people.size() - 1;
        int ans = 0;
        while(start <= end) {
            if(people[start] + people[end] <= limit) {
                start++;
                end--;
            }
            else {
                end--;
            }
            ans++; 
        } 
        return ans;
    }
};

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int ans = 0;
        while(i <= j) {
            if (i == j) {
                ++ans;
                break;
            }
            if(people[i] + people[j] <= limit) {
                ++ans;
                ++i;
                --j;
            }
            else {
                ++ans;
                --j;
            }
        }
        return ans;
    }
};