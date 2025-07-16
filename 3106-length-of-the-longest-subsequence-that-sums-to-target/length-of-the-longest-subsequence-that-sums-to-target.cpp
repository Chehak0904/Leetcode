class Solution {
public:
    int f(int i,int t,vector<int>&nums,vector<vector<int>>&dp){
        if(t==0) return 0;
        if(i>=nums.size()) return INT_MIN;
        if(dp[i][t]!=-1) return dp[i][t]; 
         int take=INT_MIN;
         if(nums[i]<=t) {
            int  p=f(i+1,t-nums[i],nums,dp);
            if(p!=INT_MIN) take=1+p;
            }
         int not_take=f(i+1,t,nums,dp);
         return dp[i][t]=max(take,not_take);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int res=f(0,target,nums,dp);
        if(res==INT_MIN) return -1;
        return  res;

        
    }
};