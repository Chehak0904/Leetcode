class Solution {
public:
    int solve(int idx,vector<int>&nums,int mod,vector<vector<int>>&dp){
        if(idx>=nums.size()){
            return (mod==0)?0:INT_MIN;
        }
        if(dp[idx][mod]!=-1) return dp[idx][mod];
        int take=solve(idx+1,nums,(mod+nums[idx])%3,dp);
        if(take!=INT_MIN) take+=nums[idx];
        int not_take=solve(idx+1,nums,mod,dp);
        return dp[idx][mod]=max(take,not_take);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        int ans=solve(0,nums,0,dp);
        return max(ans,0);
        
    }
};