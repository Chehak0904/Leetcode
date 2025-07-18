class Solution {
public:
    // int fun(int prev, int i, vector<int>& nums, int k, int mod, vector<vector<int>>& dp) {
    //     if (i == nums.size()) return 0;
    //     if (dp[prev + 1][i] != -1) return dp[prev + 1][i];

    //     int take = 0, skip = 0;

    //     if (prev == -1 || (nums[prev] + nums[i]) % k == mod) {
    //         take = 1 + fun(i, i + 1, nums, k, mod, dp);
    //     }
    //     skip = fun(prev, i + 1, nums, k, mod, dp);

    //     return dp[prev + 1][i] = max(take, skip);
    // }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        vector<vector<int>>dp(n,vector<int>(k,1));
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++ ){
                int mod=(nums[i]+nums[prev])%k;
                dp[i][mod]=max(dp[i][mod],1+dp[prev][mod]);
                len=max(len,dp[i][mod]);

            }

        }
        return len;
        
        
    }
};
