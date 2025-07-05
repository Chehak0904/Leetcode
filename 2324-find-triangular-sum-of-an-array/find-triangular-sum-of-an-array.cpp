class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int st=0;st<n-1;st++){
            for(int i=0;i<n-1-st;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
        
    }
};