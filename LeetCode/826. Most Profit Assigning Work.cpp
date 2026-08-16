// 我是用预先计算的方式做的，不过比较起来好像还是排序比较快

class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n=d.size();
        int m=w.size();
        long ans=0;
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++){
            a[i]=make_pair(d[i],p[i]);
        }
        sort(a.begin(),a.end());
        vector<int>pref(n);
        pref[0]=a[0].second;
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],a[i].second);
        }
        for(int i=0;i<m;i++){
            int idx = upper_bound(a.begin(), a.end(),
                      make_pair(w[i], INT_MAX)) - a.begin();
            idx--;
            if(idx>=0 && idx<n){
                ans += pref[idx];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> rec(100001, 0);
        int maxN = 0;
        for(int i = 0; i < difficulty.size(); ++i) {
            rec[difficulty[i]] = max(rec[difficulty[i]], profit[i]);
            maxN = max(maxN, difficulty[i]);
        }

        for(int w : worker) {
            maxN = max(maxN, w);
        }

        int oldMax = 0;
        for(int i = 0; i <= maxN; ++i) {
            rec[i] = max(rec[i], oldMax);
            oldMax = rec[i];
        }

        int ans = 0;
        for(int w : worker) {
            ans += rec[w];
        }
        return ans;
    }
};