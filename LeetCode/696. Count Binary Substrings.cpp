// 思路都是一样的，记录连续的0和1个数，然后取较小值就是可以添加的答案数量，但是最佳答案常数时间更佳

class Solution {
    public:
        int countBinarySubstrings(string s) {
            vector<int> count(2, 0);
            int res = 0;
            int last = -1;
            for (auto c : s) {
                int cur = c - '0';
                if (cur == last) {
                    count[cur]++;
                }
                else {
                    count[cur] = 1;
                }
                int other = 1 - cur;
                if (count[cur] <= count[other]) {
                    ++res;
                }
                last = cur;
            }
            return res;
        }
    };


    class Solution {
        public:
            int countBinarySubstrings(string s) {
                int n=s.size();
                int res=0,curr=1,pre=0;
        
                for(int i=1;i<n;i++){
                    if(s[i-1]==s[i]) curr++;
                    else{
                        res+=min(pre,curr);
                        pre=curr;
                        curr=1;
                    }
                }
            return res+min(curr,pre);
                
            }
        };