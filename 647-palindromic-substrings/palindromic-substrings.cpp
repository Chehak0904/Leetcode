class Solution {
public:
    bool solve(string &s, int i, int j,vector<vector<int>> &dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]= solve(s,i+1,j-1,dp);
        }
        return dp[i][j]= false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};