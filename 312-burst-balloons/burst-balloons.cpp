class Solution {
public:
    int solve(int i, int j, vector<int> &nums,vector<vector<int>>&dp) {
        if (i > j)
            return 0;
         if(dp[i][j]!=-1) return dp[i][j];   
        int ans = INT_MIN;
        for (int k = i; k <= j; k++) {
            int cost = solve(i, k - 1, nums,dp) + solve(k + 1, j, nums,dp) +
                       nums[i - 1] * nums[k] * nums[j + 1];
            ans = max(ans, cost);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n + 2, 1);
        for (int i = 0; i < n; i++) {
            temp[i + 1] = nums[i];
        }
        int m=temp.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(1,temp.size()-2,temp,dp );
    }
};