class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>preSum(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            preSum[i]=sum;
        }
        for(int i=n-1;i>=2;i--){
            if(nums[i]<preSum[i-1]) return preSum[i];
        }
        return -1;
        
    }
};