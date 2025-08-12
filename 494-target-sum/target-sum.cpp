class Solution {
public:
    int func(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size()) return target == 0 ? 1 : 0;
        if (target < -1000 || target > 1000) return 0; // pruning

        if (dp[idx][target + 1000] != -1) return dp[idx][target + 1000];

        int op1 = func(idx + 1, target - nums[idx], nums, dp);
        int op2 = func(idx + 1, target + nums[idx], nums, dp);

        return dp[idx][target + 1000] = op1 + op2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return func(0, target, nums, dp);
    }
};
