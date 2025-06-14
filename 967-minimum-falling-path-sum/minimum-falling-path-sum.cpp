class Solution {
public:
    int solve(int i,int j ,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int left=INT_MAX;
        int right=INT_MAX;
        int down=solve(i+1,j,matrix,dp);
        if(j-1>=0){
            left=solve(i+1,j-1,matrix,dp);
        }
        if(j+1<n){
            right=solve(i+1,j+1,matrix,dp);
        }
        return dp[i][j]=min(down,min(left,right))+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(0,i,matrix,dp));
        }
        return ans;

        
    }
};