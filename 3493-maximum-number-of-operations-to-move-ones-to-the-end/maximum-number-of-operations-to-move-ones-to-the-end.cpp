class Solution {
public:
    int maxOperations(string s) {
        int op=0;
        int cnt=0;
        int i=0;
        int n=s.length();
        while(i<n){
            if(s[i]=='1') cnt++;
            if( (s[i]=='0' && i==n-1) || (s[i]=='0' &&s[i+1]=='1' )) op+=cnt;
            i++;
        }
        return op;
        
    }
};