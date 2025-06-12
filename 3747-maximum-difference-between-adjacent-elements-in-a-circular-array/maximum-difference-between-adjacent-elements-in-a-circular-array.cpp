class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int max_diff=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int temp=abs(nums[i]-nums[i+1]);
            max_diff=max(temp,max_diff);
        }
        max_diff=max(max_diff,abs(nums[n-1]-nums[0]));
        return max_diff;
        
    }
};