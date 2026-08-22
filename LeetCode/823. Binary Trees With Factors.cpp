// 自己剪枝有点问题，虽然能过，但是不够快，题意理解不太对

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n= arr.size();
        long long  m= 1e9+7;
        sort(arr.begin(),arr.end());
        unordered_map<int,long long > p;
        long long t=0;
        for(int i=0;i<n;++i){
            p[arr[i]]=1;
            for(int j=0;j<i;++j){
                if((long long) arr[j]* arr[j]> arr[i]){
                    break;
                }
                if(arr[i]% arr[j]==0){
                    int r=arr[i]/arr[j];
                    if(p.count(r)){
                        long long n=(p[arr[j]]*p[r])%m;
                        if(arr[j]!=r){
                            p[arr[i]]=(p[arr[i]]+n*2)%m;
                        }else{
                            p[arr[i]]=(p[arr[i]]+n)%m;
                        }
                    }
                }
            }
            t=(t+p[arr[i]])%m;
        }
        return t;
    }
};

class Solution {
public:
    int ModNum = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long long, long long> rec;
        sort(arr.begin(), arr.end());
        long long n = arr.size();
        for(int i = 0; i < n; ++i) {
            rec[arr[i]]++;
            for(int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && rec[arr[i] / arr[j]] > 0) {
                    rec[arr[i]] += rec[arr[j]] * rec[arr[i] / arr[j]] % ModNum;
                    rec[arr[i]] %= ModNum;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = (ans + rec[arr[i]]) % ModNum;
        }

        return ans;
    }
};