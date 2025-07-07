class Solution {
public:
    int f(int i,int b,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        int p=0;
        if(b==1){
            int op1=0+f(i+1,b,prices,dp);
            int op2=f(i+1,0,prices,dp)-prices[i];
            p=max({op1,op2});
        }
        else{
            int op1=0+f(i+1,b,prices,dp);
            int op2=prices[i]+f(i+2,1,prices,dp);
            p=max({op1,op2});
        }
        return dp[i][b]=p;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
        
    }
};