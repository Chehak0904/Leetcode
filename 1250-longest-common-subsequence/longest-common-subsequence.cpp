class Solution {
public:
    int solve(int idx1,int idx2,string &text1,string &text2,vector<vector<int>>&dp){
          if(idx1==text1.size() || idx2==text2.size()){
            return 0;
          }
            if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
           }
          
        
           if(text1[idx1]==text2[idx2]){
               return dp[idx1][idx2]=1+solve(idx1+1,idx2+1,text1,text2,dp);

           }
           
            int pos1=solve(idx1+1,idx2,text1,text2,dp);
            int pos2=solve(idx1,idx2+1,text1,text2,dp);
            return dp[idx1][idx2]=max(pos1,pos2); 

           

    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,text1,text2,dp);
        
    }
};