class Solution {
public: 
    bool solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return solve(i+1,j-1,s,dp);
        }
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};