class Solution {
public:
    bool f(int i,int j,string& s,string &p,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];

       if(s[i]==p[j]|| p[j]=='?'){
            return dp[i][j]= f(i-1,j-1,s,p,dp);
       }
       else if(p[j]=='*'){
             int op1=f(i-1,j,s,p,dp);
             int op2=f(i,j-1,s,p,dp);
             return dp[i][j]=op1|op2;

       }
       return dp[i][j]= false;


    }
    bool isMatch(string s, string p) {
        int n1=s.length();
        int n2=p.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,s,p,dp);
        
    }
};