class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
         vector<vector<int>>dp(n,vector<int>(n,0));
        dp[0][0] = triangle[0][0];
         for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int top = 1e9, diag = 1e9;
                if (j <= i - 1)     
                    top = dp[i-1][j];

                if (j - 1 >= 0)      
                    diag = dp[i-1][j-1];

                dp[i][j] = triangle[i][j] + min(top, diag);

            }
         }
         return *min_element(dp[n-1].begin(),dp[n-1].end());
        
    }
};