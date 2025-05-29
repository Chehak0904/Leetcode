class Solution {
public:
    int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
       if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()){
        return INT_MAX;
       }
       if(i==matrix.size()-1){
        return matrix[i][j];
       }
       if(dp[i][j]!=INT_MAX){
        return dp[i][j];
       }

       
       int op1=solve(matrix,i+1,j-1,dp);
       int op2=solve(matrix,i+1,j,dp);
       int op3=solve(matrix,i+1,j+1,dp);
       return dp[i][j]=matrix[i][j]+min(op1,min(op2,op3));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            ans=min(ans,solve(matrix,0,i,dp));
        }
        return ans;
        
    }
};