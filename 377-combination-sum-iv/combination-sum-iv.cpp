class Solution {
public:
    int func(vector<int>& nums, int target, vector<int>& dp) {
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for (auto num : nums) {
            if (num <= target) {
                ans += func(nums,target-num,dp);
            }
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return func(nums,target,dp);
    }
};