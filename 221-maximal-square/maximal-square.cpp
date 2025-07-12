class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        
        for(int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            ans = max(ans, dp[i][0]);
        }
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            ans = max(ans, dp[0][j]);
        }

        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int left = dp[i][j-1];
                    int top = dp[i-1][j];
                    int diag = dp[i-1][j-1];
                    dp[i][j] = min({left, top, diag}) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans * ans; 
    }
};
