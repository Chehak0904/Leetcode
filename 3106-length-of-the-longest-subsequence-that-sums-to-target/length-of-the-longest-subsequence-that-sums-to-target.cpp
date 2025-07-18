class Solution {
public:
    // / int f(int i,int t,vector<int>&nums,vector<vector<int>>&dp){
    //     if(t==0) return 0;
    //     if(i>=nums.size()) return INT_MIN;
    //     if(dp[i][t]!=-1) return dp[i][t];
    //      int take=INT_MIN;
    //      if(nums[i]<=t) {
    //         int  p=f(i+1,t-nums[i],nums,dp);
    //         if(p!=INT_MIN) take=1+p;
    //         }
    //      int not_take=f(i+1,t,nums,dp);
    //      return dp[i][t]=max(take,not_take);
    // }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-0));
        for(int i=1;i<=target;i++){
            dp[n][i]=-1e9;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=target;j++){
                int skip=dp[i+1][j];
                int take=-1e9;
                if(nums[i]<=j){
                    take=1+dp[i+1][j-nums[i]];
                }
                dp[i][j]=max(skip,take);
            }
        }
       int ans= dp[0][target];
       return (ans<0)?-1:ans;
    
    }
};