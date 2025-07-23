class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        long long cnt=0;
        while(j<n){
            if(nums[j]==0){
                i=j;
                while(j<n && nums[j]==0){
                    cnt+=j-i+1;
                    j++;
                }
            }
            else{
                 j++;
            }
        }
        return cnt;
    }
};