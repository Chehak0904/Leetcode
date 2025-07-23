class Solution {
public:
    int fun(int i,vector<int>&jd,int d,vector<vector<int>>&dp){
        int n=jd.size();
        if(d==1){
            int maxi=0;
            for(int k=i;k<jd.size();k++){
                maxi=max(maxi,jd[k]);
            }
            return maxi;
        }
        if(dp[i][d]!=-1) return dp[i][d];
        int curr_max=0;
        int ans=INT_MAX;
        for(int j=i;j<=n-d;j++){
            curr_max=max(curr_max,jd[j]);
            int t=fun(j+1,jd,d-1,dp);
            ans=min(ans,t+curr_max);
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n) return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return fun(0,jobDifficulty,d,dp);
        
    }
};