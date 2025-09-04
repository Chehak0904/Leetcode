class Solution {
public:
    bool solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return false;
        return dp[i][j]= solve(i+1,j-1,s,dp);
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int idx=-1;
        int maxLen=-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,dp)){
                    int len=j-i+1;
                    if(len>maxLen){
                        maxLen=len;
                        idx=i;
                    }
                }
            }
        }
        return s.substr(idx,maxLen);

    }
};