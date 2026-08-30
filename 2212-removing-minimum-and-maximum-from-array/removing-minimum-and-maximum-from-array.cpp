class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int miniI=-1;
        int maxiI=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxiI=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                miniI=i;
            }
        }
        //think of it as left and right
        int left=min(miniI,maxiI);
        int right=max(miniI,maxiI);
        int case1=right+1;
        int case2=n-left;
        int case3=(left+1+n-right);
        int ans=min({case1,case2,case3});
        return ans;


        
    }
};