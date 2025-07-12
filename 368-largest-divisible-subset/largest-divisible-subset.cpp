class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        int len=1, lastIdx=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>len){
                len=dp[i];
                lastIdx=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx=hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        return ans;
        
    }
};