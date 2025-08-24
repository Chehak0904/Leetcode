class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int maxLen=0;
        int zeros=0;
        while(j<nums.size()){
            if(nums[j]==0) zeros++;
            while(zeros>=2){
                if(nums[i]==0) zeros--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen-1;
        
    }
};