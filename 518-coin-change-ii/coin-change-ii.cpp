class Solution {
public:
    int solve(int idx,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(idx>=coins.size()){
            if(amt==0) return 1;
            return 0;
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int take=0;
        if(amt>=coins[idx]){
            take=solve(idx,amt-coins[idx],coins,dp);
        }
        int not_take=solve(idx+1,amt,coins,dp);
        return dp[idx][amt]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
        
    }
};