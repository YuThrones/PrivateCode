// 思路没什么问题，就是一个一个push_back太慢了

class Solution {
public:
    string reformatNumber(string number) {

        string n;
        for(char c:number)if(c!=' ' && c!='-')n.push_back(c);
        string ans="";
        int Size=n.size();
        for(int i=0;i<n.size()-1;i+=3){
            if(Size-i<=3){
                ans+=n.substr(i,Size);

            }
            else if(Size-i==4){
                ans+=n.substr(i,2);
                ans+='-';
                ans+=n.substr(i+2,2);
            }else{
          
            ans+=n.substr(i,3)+'-';
            
            }
        }
        return ans;



        
    }
};

class Solution {
public:
    string reformatNumber(string number) {
        string ans = "";
        for(auto c : number) {
            if (c >= '0' && c <= '9') {
                ans.push_back(c);
            }
        }
        if (ans.length() > 3) {
            string temp = "";
            int s = ans.length();
            int i = 0;
            while(i < s) {
                cout << i << " " << s << " " << ans[i] << endl;
                if (s - i > 4 || s - i == 3) {
                    for(int j = 0; j < 3; ++j){
                        temp.push_back(ans[i]);
                        ++i;
                    }
                }
                else {
                    for(int j = 0; j < 2; ++j){
                        temp.push_back(ans[i]);
                        ++i;
                    }
                }
                if (i != s) {
                    temp.push_back('-');
                }
            }
            return temp;
        }
        return ans;
    }
};