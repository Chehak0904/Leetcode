class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0;int j=0;
        long long sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(1LL *nums[j]*(j-i+1)-sum>k){
                sum-=nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;


        }
        return ans;
    }
};