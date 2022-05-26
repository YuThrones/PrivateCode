// 第一反应就是用带记忆的递归解决，虽然ac了但是速度有点慢
// 看了下最快方法，貌似是通过打表的方式找规律做的

class Solution {
public:
    unordered_map<int, int> rec;
    int numSquares(int n) {
        if (rec.find(n) != rec.end()) return rec[n];
        int maxVal = sqrt(n);
        if (maxVal * maxVal == n) {
            rec[n] = 1;
            return rec[n];
        }
        int res = INT_MAX;
        for (int i = maxVal; i > 0; --i) {
            res = min(res, numSquares(n - i * i) + 1);
        }
        rec[n] = res;
        return rec[n];
    }
};

class Solution {
public:
int issqr(int n)
{
int x=sqrt(n);
return n==x*x;
}
int numSquares(int n)
{
if(issqr(n))
{
return 1;
}
for(int i=1;i*i<n;i++)
{
if(issqr(n-i*i))
return 2;
}
while(n%4==0)
n=n/4;
if(n%8!=7)
{
return 3;
}
return 4;
}
};