class Solution {
public:
    int solve(int idx,int ans,vector<int>&nums,int target ,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(ans==target) return 1;
            return 0;
        }
        if(dp[idx][ans+1000]!=-1){
            return dp[idx][ans+1000];
        }
        int take=solve(idx+1,ans+nums[idx],nums,target,dp);
        int not_take=solve(idx+1,ans-nums[idx],nums,target,dp);
        return dp[idx][ans+1000]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return solve(0,0,nums,target,dp);
        
    }
};