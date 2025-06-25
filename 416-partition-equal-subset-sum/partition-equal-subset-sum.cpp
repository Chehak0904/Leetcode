class Solution {
public:
    // int t[201][20001];
    // bool solve(vector<int>&nums,int i,int x){
    //     if(x==0) return true;
    //     if(i>=nums.size()) return false;
    //     if(t[i][x]!=-1){
    //         return t[i][x];
    //     }
    //     bool take=false;
    //     if(nums[i]<=x){
    //         take=solve(nums,i+1,x-nums[i]);
    //     }
    //     bool not_take=solve(nums,i+1,x);
    //     return t[i][x]=take||not_take;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 != 0) return false;
        int x = s / 2;

        vector<vector<bool>> dp(n, vector<bool>(x + 1, false));
        
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= x) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= x; target++) {
                bool not_take = dp[i - 1][target];
                bool take = false;
                if (nums[i] <= target) {
                    take = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = take || not_take;
            }
        }
        return dp[n - 1][x];
        
    }
};