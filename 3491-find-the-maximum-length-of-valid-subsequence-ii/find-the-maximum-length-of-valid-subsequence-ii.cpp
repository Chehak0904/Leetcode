class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<vector<int>>dp(k,vector<int>(n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                    int k_=(nums[i]+nums[j])%k;
                    dp[k_][i]=max(dp[k_][i],1+dp[k_][j]);
                    ans=max(ans,dp[k_][i]);
            }

        }
        return ans;
        
    }
};