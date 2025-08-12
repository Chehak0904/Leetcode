class Solution {
public:
    int func(int target,vector<int>& nums,vector<int>& dp){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int take=0;
        for(int num:nums){
            if(num<=target){
                take+=func(target-num,nums,dp);
            }
        }
        return dp[target]= take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return func(target,nums,dp);
    }
};