class Solution {
public:
    int func(int idx, vector<int>& nums,vector<int>&dp) {
        if(idx>=nums.size()-1) return 0; 
        if(dp[idx]!=-1) return dp[idx];
        int steps = nums[idx];
        int ans = 1e9;
        for (int i = 1; i <= steps; i++) {
            int t = 1 + func(idx+i, nums,dp);
            ans = min(t, ans);
        }
        return dp[idx]= ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return func(0,nums,dp);
    }
};