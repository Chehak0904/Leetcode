class Solution {
public:
    long long solve(int i,vector<int>&values,vector<int>&freq,vector<long long>&dp){
        if(i>=values.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        long long skip=solve(i+1,values,freq,dp);
        long long take=1LL* freq[i]*values[i];
        int j=i+1;
        while(j<values.size() && values[j]-values[i]<3){
            j++;
        }
        take+=solve(j,values,freq,dp);
        return dp[i]=max(take,skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        sort(power.begin(),power.end());
        vector<int>values;
        vector<int>freq;
        for(int i=0;i<n;i++){
            int p=power[i];
            int f=1;
            while(i+1<n && power[i+1]==p){
                i++;
                f++;
                
            }
            values.push_back(p);
            freq.push_back(f);

        }
        vector<long long>dp(n,-1);
        return solve(0,values,freq,dp);

        
    }
};