class Solution {
public:
    int countHomogenous(string s) {
        int M=1e9+7;
        long long ans=0;
        long long cnt=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                ans=(ans+((cnt)*(cnt+1))/2)%M;
                cnt=1;
            }
        }
        ans=(ans+((cnt)*(cnt+1))/2)%M;
        return (int) ans;

        
        
    }
};