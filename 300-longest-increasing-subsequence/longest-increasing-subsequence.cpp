class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=1;
        int n=nums.size();
        vector<int>dp(n+1,1);
        for(int i=1;i<n;i++ ){
            for(int j=0;j<=i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    len=max(len,dp[i]);
                }
            }
        }
        return len;
        
    }
};