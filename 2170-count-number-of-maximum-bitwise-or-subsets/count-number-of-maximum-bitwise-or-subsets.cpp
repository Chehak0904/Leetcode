class Solution {
public: 
    int f(int i, vector<int>& nums,int ans,int maxval){
        if(i==nums.size()){
            return (ans==maxval)?1:0;
        }
        int t=f(i+1,nums,ans|nums[i],maxval);
        int nt=f(i+1,nums,ans,maxval);
        return t+nt;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxval=0;
        for(int i:nums){
            maxval=maxval|i;
        }
        return f(0,nums,0,maxval);
    }
};