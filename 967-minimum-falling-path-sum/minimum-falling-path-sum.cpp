class Solution {
public: 
    // int solve(int i,int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){

    //     if(i<0 || j>=matrix.size()) return 1e8;
    //     if(i==0) return matrix[0][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int leftdg=matrix[i][j]+solve(i-1,j-1,dp,matrix);
    //     int up=matrix[i][j]+solve(i-1,j,dp,matrix);
    //     int rightdg=matrix[i][j]+solve(i-1,j+1,dp,matrix);
    //     return dp[i][j]=min({leftdg,up,rightdg});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i+1][j];
                int leftdg=1e8, rightdg=1e8;
               if(j>0)  leftdg=matrix[i][j]+dp[i+1][j-1];
               if(j<n-1)  rightdg=matrix[i][j]+dp[i+1][j+1];
               dp[i][j]=min({down,leftdg,rightdg});
            }
        }
        int ans=1e8;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[0][j]);
        }
        return ans;
    }
};