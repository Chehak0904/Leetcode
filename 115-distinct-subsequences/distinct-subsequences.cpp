class Solution {
public:
    int recurrsive_sol(int idx1,int idx2,string&s,string& t,vector<vector<int>>&dp){
        if(idx2==t.size()) return 1;
        if(idx1==s.size()) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int not_pick=recurrsive_sol(idx1+1,idx2,s,t,dp);
        int pick=0;
        if(s[idx1]==t[idx2]) pick=recurrsive_sol(idx1+1,idx2+1,s,t,dp);
        return dp[idx1][idx2]=pick+not_pick;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return recurrsive_sol(0,0,s,t,dp);
        
    }
};