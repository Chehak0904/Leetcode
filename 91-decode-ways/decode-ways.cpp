class Solution {
public:
    bool isValid(const string& s){
        if(s.empty() || s[0]=='0') return false;
        int num=stoi(s);
        return num>=1 && num<=26;
    }
    int solve(int i,string &s,vector<int>&dp){
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        //op1;
        if(isValid(s.substr(i,1))){
            ans+=solve(i+1,s,dp);
        }
        if(i+1<s.length() && isValid(s.substr(i,2))){
            ans+=solve(i+2,s,dp);
        }
         return dp[i]=ans;

    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(0,s,dp);

        
    }
};