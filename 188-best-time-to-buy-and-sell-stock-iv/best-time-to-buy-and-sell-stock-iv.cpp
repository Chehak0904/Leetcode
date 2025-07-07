class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k+1, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int cap = 1; cap <= k; cap++) {
                for (int canBuy = 0; canBuy <= 1; canBuy++) {
                    int profit = 0;
                    if (canBuy) {
                        
                        int buy = -prices[i] + dp[i + 1][cap][0];
                        int skip = dp[i + 1][cap][1];
                        profit = max(buy, skip);
                    } else {
                        
                        int sell = prices[i] + dp[i + 1][cap - 1][1];
                        int skip = dp[i + 1][cap][0];
                        profit = max(sell, skip);
                    }
                    dp[i][cap][canBuy] = profit;
                }
            }
        }

        
        return dp[0][k][1];
    
        
    }
};