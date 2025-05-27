class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp){
         if(i==0 && j==0) return 1;
         if(i<0|| j<0 ) return 0;
         if(dp[i][j]!=-1) return dp[i][j];

        int d1=solve(i-1,j,dp);
        int d2=solve(i,j-1,dp);
        return dp[i][j]= d1+d2;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
        
    }
};