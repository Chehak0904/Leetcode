class Solution {
public:
    // int f(int i, int p, vector<int>& nums, vector<vector<int>>& dp) {
    //     if (i >= nums.size()) return 0;
    //     if (dp[i][p + 1] != -1) return dp[i][p + 1];

    //     int not_take = f(i + 1, p, nums, dp);
    //     int take = 0;

        
    //     if (p == -1 || nums[i] > nums[p]) {
    //         take = 1 + f(i + 1, i, nums, dp);
    //     }

    //     return dp[i][p + 1] = max(take, not_take);
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for(int i=n-1;i>=0;i--){
            for(int p=i-1;p>=-1;p--){
                int not_take=dp[i+1][p+1];
                int take=0;
                if(p==-1 || nums[i]>nums[p]){
                    take=1+dp[i+1][i+1];
                }
                dp[i][p+1]=max(take,not_take);
            }
        }
        return dp[0][0];

        
    }
};
