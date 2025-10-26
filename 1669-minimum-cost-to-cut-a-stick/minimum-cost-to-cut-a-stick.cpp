class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int cost=INT_MAX;
        for(int k=i;k<=j;k++){
            int t=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            cost=min(cost,t);
        }
        return dp[i][j]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int t=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(t+2,vector<int>(t+2,-1));
        return solve(1,t-2,cuts,dp);
        
    }
};