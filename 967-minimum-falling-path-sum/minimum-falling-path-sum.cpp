class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int j=0;j<m;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int d=dp[i+1][j];
                int l=INT_MAX;
                int r=INT_MAX;
                if(j-1>=0){
                    l=dp[i+1][j-1];
                }
                if(j+1<=m-1){
                    r=dp[i+1][j+1];
                }
                dp[i][j]= matrix[i][j] +min(l,min(d,r));

            }
        }
        for(int i=0;i<m;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
        
        
    }
};