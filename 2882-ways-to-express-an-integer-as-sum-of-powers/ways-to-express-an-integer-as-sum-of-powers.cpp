class Solution {
public:
    int M=1e9+7;
    long long power(int a,int x){
        long long val=1;
        for(int i=1;i<=x;i++){
            val*=a;
        }
        return val;
    }
    int func(int n,int x,int a,vector<vector<int>> &dp){
        if(n==0) return 1;
        if(n<0 || a<0) return 0;
        if(dp[n][a]!=-1) return dp[n][a];
        long long p=power(a,x);
        int take=0;
        if(p<=n){
            take=func(n-p,x,a-1,dp);
        }
        int skip=func(n,x,a-1,dp);
        return dp[n][a]= (take+skip)%M;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(n,x,n,dp);
    }
};