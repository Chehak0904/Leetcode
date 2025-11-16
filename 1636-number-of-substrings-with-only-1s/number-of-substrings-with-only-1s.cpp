class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        long long cnt=0;
        int M=1e9+7;
        for(char i:s){
              if(i=='1') cnt++;
              else if( i=='0'){
                ans=(ans+((cnt)*(cnt+1))/2)%M;
                cnt=0;
              }
        }
        if(cnt!=0) ans=(ans+(cnt*(cnt+1))/2)%M;
        return (int)ans;
        
    }
};