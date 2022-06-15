// 这道题我一开始想太复杂了，一直在纠结字符串的细节，事实上没必要，看别人答案，直接尝试第一二个数，然后尝试递归即可

class Solution {
    
    // isFibPossible() function takes 2 numbers ( n1 & n2 ), string s(i.e num),
    // integer j which state "form where n3 will be starting" in s(/num). 
    bool isFibPossible( long n1, long n2, string& s, int j, bool atleast3 ){
        
        // If we are at the end of s and if we covered atleast 3 numbers
        // then this is valid fibonacci sequence. So, return true.
        if( s.length()==j && atleast3 )
            return true;
        
        // n3 = n1 + n2; 
        string n3 = to_string( n1 + n2 );
        // calculate len of n3 and make sure u don't over shoot s.length;
        int len = min( s.length()-j, n3.length() );
        
        // if we found n3 then go on depth and find n4, n5, ... so on;
        if( s.substr( j, len) == n3 )
            return isFibPossible( n2, stol(n3), s, j+len, true);
        
        return false;
        
    }
public:
    bool isAdditiveNumber(string num) {
        
        int n = num.size();
        
        for( int i=1; i<n-1 ; i++ ){
            
            // number should not start with leading 0;
            if( num[0] == '0' && i > 1 ) return false;
            // pick first number n1;
            long n1 = stol( num.substr(0, i) );
            
            
            for( int j=i+1; j<n; j++ ){
                
                // number should not start with leading 0;
                if( num[i] == '0' && j-i > 1 ) break;
                // pick second number n2;
                long n2 = stol( num.substr(i, j-i) );
                
                // now recusively check whether given string forms
                // a fibonacci sequence;
                bool isFibSeq = isFibPossible( n1, n2, num, j, false);
                if( isFibSeq ) return true;
                
            }
            
        }
        
        return false;
    }
};