class Solution {
public:
    int func(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=1e9;
        for(int i=1;i<=nums[idx];i++){
            ans=min(ans,1+func(idx+i,nums,dp));
        }
       return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return func(0,nums,dp);
        
        
    }
};