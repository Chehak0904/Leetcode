class Solution {
public:
    int solve(vector<int>&coins,int ind,int amt,vector<vector<int>>&dp){
        if(amt==0) return 0 ;
        if(amt<0) return INT_MAX;
        if(ind==coins.size()) return INT_MAX;
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        
        int op1=solve(coins,ind,amt-coins[ind],dp);
        if(op1!=INT_MAX){
            op1+=1;
        }
        int op2=solve(coins,ind+1,amt,dp);
        return dp[ind][amt]=min(op1,op2);

    }
    int coinChange(vector<int>& coins, int amount) {
        // if(coins.size()==1 && coins[0]<amount) return -1;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res=solve(coins,0,amount,dp);
        return res==INT_MAX?-1:res;
        
    }
};