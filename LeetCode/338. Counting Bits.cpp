// 本想来着只是简单的二进制转换，看了下最快答案，事实上还可以优化，只需要找到当前数右移一位的数的1的数量，然后加上最后一位数就行

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        res[0] = 0;//base case
        
        for(int i=1;i<=n;i++)
        {
			res[i] = (i % 2) + res[i/2];
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            ans.push_back(cal(i));
        }
        return ans;
    }
    
    int cal(int n) {
        int ans = 0;
        while(n > 0) {
            ans += n % 2;
            n /= 2;
        }
        return ans;
    }
};