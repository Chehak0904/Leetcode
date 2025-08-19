class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len=1;
        int ans=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]+1){
                len++;
                ans=max(ans,len);
            }
            else{
                len=1;
            }
        }
        return ans;
        
    }
};