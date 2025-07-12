class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                len++;
                ans=max(ans,len);
            }else{
                len=1;
            }

        }
        return ans;
        
    }
};