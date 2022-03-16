// 这道题自己没想出比较优雅的解法，看了下讨论，也是用求gcd然后遍历的方式，O(n ^ 2)的复杂度
// 看了下最佳解法，事实上也是这个思路，只是重写了unordered_map的哈希函数，感觉没太大必要

class Solution {
public:
    int maxPoints(vector<vector<int>>& points){
        int n = points.size();
        if(n == 1) return 1;
        int res = 0;
        for(int i=0; i<n; i++){
            map<pair<int, int>, int> m;
            int dup = 1;
            for(int j=i+1; j<n; j++){
                vector<int> diff(2,0);
                diff[0] = points[j][0]-points[i][0];
                diff[1] = points[j][1]-points[i][1];
                if(diff[0]==0 and diff[1]==0) dup++;
                else{
                    int factor = gcd(diff[0], diff[1]);
                    diff[0] /= factor;
                    diff[1] /= factor;
                    if(diff[0] == 0) {
                        diff[1] = 1;
                    } 
                    else if(diff[0] < 0){
                        diff[0] *= -1;
                        diff[1] *= -1;
                    }
                    m[make_pair(diff[0], diff[1])]++;
                }
            }
            res = max(res,dup);
            for(auto i: m)
                res=max(res, i.second+dup);
        }
        return res;
    }
    
    int gcd(int a, int b) {
        while(b){
            a = a%b;
            swap(a, b);
        }
        return a;
    }
};