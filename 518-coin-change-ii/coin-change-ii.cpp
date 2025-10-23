class Solution {
public: 
    int f(int i,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0) return 1;
        if(i==coins.size()-1){
            return (amount%coins[i]==0)? 1:0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_take=f(i+1,amount,coins,dp);
        int take=0;
        if(coins[i]<=amount){
            take=f(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]= not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(0,amount,coins,dp);
    }
};