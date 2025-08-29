class Solution {
public:
    int func(int i, int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=-1e8;
        for(int idx=i;idx<=j;idx++){
            int cost=nums[i-1]*nums[idx]*nums[j+1]+func(i,idx-1,nums,dp)+func(idx+1,j,nums,dp);
            ans=max(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(1,n,nums,dp);
    }
};