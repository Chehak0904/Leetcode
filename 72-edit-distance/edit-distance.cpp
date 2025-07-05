class Solution {
public:
    int f(int i,int j,string& word1,string& word2,vector<vector<int>>&dp){
        if(i==word1.length() && j== word2.length()) return 0;
        if(i==word1.length()) return word2.length()-j;
        if(j== word2.length()) return word1.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return f(i+1,j+1,word1,word2,dp);
        int op1=1+f(i,j+1,word1,word2,dp);
        int op2=1+f(i+1,j,word1,word2,dp);
        int op3=1+f(i+1,j+1,word1,word2,dp);
        return dp[i][j]=min({op1,op2,op3});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,word1,word2,dp);
        
    }
};