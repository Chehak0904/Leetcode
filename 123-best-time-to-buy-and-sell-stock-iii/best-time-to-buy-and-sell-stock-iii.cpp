class Solution {
public:
    int solve(int idx, int cap, int canBuy, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (idx == prices.size() || cap == 0)
            return 0;
        if (dp[idx][cap][canBuy] != -1)
            return dp[idx][cap][canBuy];
        int profit = 0;
        if (canBuy) {
            int op1 = solve(idx + 1, cap, canBuy, prices, dp);
            int op2 = solve(idx + 1, cap, !canBuy, prices, dp) - prices[idx];
            profit = max(op1, op2);

        } else {
            int op1 = solve(idx + 1, cap, canBuy, prices, dp);
            int op2 =
                solve(idx + 1, cap - 1, !canBuy, prices, dp) + prices[idx];
            profit = max(op1, op2);
        }
        return dp[idx][cap][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(3, vector<int>(2, -1)));

        return solve(0, 2, 1, prices, dp);
    }
};