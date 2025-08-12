class Solution {
public:
    int M=1e9+7;
    int f(int n,int x,int i,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        int curr_num=1;
        for (int k = 0; k < x; k++) curr_num *= i;
        if(curr_num>n) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        int take=0;
        if(curr_num<=n)take=f(n-curr_num,x,i+1,dp);
        int not_take=f(n,x,i+1,dp);
        return dp[i][n]=(take +not_take)%M;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n,x,1,dp);
        
    }
};