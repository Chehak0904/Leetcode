class Solution {
public:
    int solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>=nums.size()){
            if(target==0) return 0;
            return INT_MAX;
        }
        if(dp[idx][target]!=-1)return dp[idx][target];
        int take=INT_MAX;
        if(target>=nums[idx]){
             int t=solve(idx,target-nums[idx],nums,dp);
             if(t!=INT_MAX) take=1+t;
             else take=INT_MAX;
        }
        int not_take=solve(idx+1,target,nums,dp);
        return dp[idx][target]= min(take,not_take);
        

    }
    int numSquares(int n) {
        vector<int>arr;
        int i=1;
        while(true){
            if(i*i<=n){
                arr.push_back(i*i);
            }
            else{
                break;
            }
            i++;
        }
        vector<vector<int>>dp(arr.size(),vector<int>(n+1,-1));
        return solve(0,n,arr,dp);

    }
};