class Solution {
public:
    int solve(int idx,vector<int>& arr,int k,vector<int>&dp){
        if(idx>=arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int maxi=arr[idx];
        int ans=INT_MIN;
        for(int i=idx;i<idx+k && i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            int temp=maxi*(i-idx+1)+solve(i+1,arr,k,dp);
            ans=max(ans,temp);

        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return solve(0,arr,k,dp);

    }
};