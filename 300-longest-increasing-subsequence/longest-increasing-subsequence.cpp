class Solution {
public:
    int f(int i, int p, vector<int>& nums, vector<vector<int>>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i][p + 1] != -1) return dp[i][p + 1];

        int not_take = f(i + 1, p, nums, dp);
        int take = 0;

        
        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + f(i + 1, i, nums, dp);
        }

        return dp[i][p + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};
