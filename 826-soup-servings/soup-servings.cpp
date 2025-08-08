class Solution {
public:
    double f(int a,int b,vector<vector<double>>&dp){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0 && b>0)  return 1.0;
        if(a>0 && b<=0)  return 0.0;
        if(dp[a][b]!=-1) return dp[a][b];
        double d=0.25* f(a-100,b,dp);
        double e=0.25*f(a-75,b-25,dp);
        double h=0.25*f(a-50,b-50,dp);
        double g=0.25*f(a-25,b-75,dp);
        return dp[a][b]=d+e+h+g;
    }
    double soupServings(int n) {
        if(n>5000) return 1;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return f(n,n,dp);
    }
};