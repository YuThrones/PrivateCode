// 这道题是最快答案是用转long类型做的，可能要考察的应该是string形式的加减乘除

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator  == 0) return "0";
        string ans ;
        ans+=((numerator>0)^(denominator>0))?"-":"";
        long n=abs(numerator),d=abs(denominator);
        ans+=to_string(n/d);
        n=n%d;
        if(!n) return ans;
        ans+=".";
        unordered_map<long ,int> mp;
        mp[n]=ans.size();
        while(n)
        {
            n*=10;
            ans+=to_string(n/d);
            n=n%d;
            if(mp[n])
            {
                ans.insert(mp[n],"(");
                ans+=")";
                break;
           }
            mp[n]=ans.size();
        }
        return ans ;
        
    }
};