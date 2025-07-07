class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));  
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                int p = 0;
                if (j == 1) {  
                    int op1 = dp[i + 1][1];                  
                    int op2 = -prices[i] + dp[i + 1][0];    
                    p = max(op1, op2);
                } else {  
                    int op1 = dp[i + 1][0];                  
                    int op2 = prices[i]-fee+ dp[i + 1][1];      
                    p = max(op1, op2);
                }
                dp[i][j] = p;
            }
        }

        return dp[0][1]; 
        
    }
};