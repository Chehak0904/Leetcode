class Solution {
public:
    int helper(vector<int>&nums,int k){
        int i=0;
        int j=0;
        int ans=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                cnt++;
            }
            while(cnt>k){
                if(nums[i]%2!=0){
                    cnt--;
                }
                i++;
            }
            ans+=j-i+1;
            j++;
            
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
        
    }
};