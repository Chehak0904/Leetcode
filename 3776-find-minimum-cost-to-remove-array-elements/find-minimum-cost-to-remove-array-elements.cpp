class Solution {
public:
    int fun(int preIdx,int idx,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==nums.size()) return nums[preIdx];
        if(idx==nums.size()-1) return max(nums[preIdx],nums[idx]);
        if(dp[preIdx][idx]!=-1) return dp[preIdx][idx];
        
        int op1=max(nums[preIdx],nums[idx])+fun(idx+1,idx+2,nums,dp);
        int op2=max(nums[preIdx],nums[idx+1])+fun(idx,idx+2,nums,dp);
        int op3=max(nums[idx],nums[idx+1])+fun(preIdx,idx+2,nums,dp);
        return dp[preIdx][idx]=min({op1,op2,op3});
    }
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(0,1,nums,dp);

        
    }
};