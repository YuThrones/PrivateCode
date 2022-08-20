// 这道题我的做法是根据图去判断哪些线有可能相交，只留下有可能相交的进行判断，但是很复杂
// 标准答案似乎是用距离直接判断，只需要判断之前5条线段有没有相交即可，在之前5条不想交的情况，没有其他可能相交

class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        int n = d.size();
        if (n <3) return false;
        int i;
        if (d[0] <= d[2] && d[1]<=0) return true;

        for (i=3; i<min(n,4); i++)
         if (d[i-2] <= d[i] && d[i-1]<=d[i-3]) return true;

        if (n>=5)
        {
            i = 4;
            if (d[i-2] <= d[i] && d[i-1]<=d[i-3]) return true;
                
            if (d[i - 1] <= d[i - 3] && d[i - 1] >= d[i - 3]  &&
                d[i - 2] >= d[i - 4] && d[i - 2] <= d[i - 4] + d[i]) return true;
        }
        for (i=5; i<n; i++)
        {
            if (d[i-2] <= d[i] && d[i-1]<=d[i-3]) return true;
                
            if (d[i - 1] <= d[i - 3] && d[i - 1] >= d[i - 3] - d[i - 5] &&
                d[i - 2] >= d[i - 4] && d[i - 2] <= d[i - 4] + d[i]) return true;
        }
       return false;
       
    }
};