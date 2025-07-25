class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0)return 0;
        if(i==0 && j==0){
            if(grid[i][j]==1){
                return 0;
            }
            return 1;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=solve(i,j-1,grid,dp);
        int up=solve(i-1,j,grid,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};