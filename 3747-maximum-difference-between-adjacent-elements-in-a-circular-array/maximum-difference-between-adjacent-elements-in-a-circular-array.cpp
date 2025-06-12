class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int diff=abs(nums[i]-nums[(i+1)%n]);
            ans=max(ans,diff);
        }
        return ans;
    }
};