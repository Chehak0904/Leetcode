class Solution {
public:
    int MOD = 1e9+7;
    int f(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(idx>=nums.size()) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take=f(0,target-nums[idx],nums,dp);
        int not_take=f(idx+1,target,nums,dp);
        return dp[idx][target]=take+not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return f(0,target,nums,dp);
    }
};
