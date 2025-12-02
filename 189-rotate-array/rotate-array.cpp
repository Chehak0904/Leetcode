class Solution {
public:
    void reverse_(int i,int j,vector<int>&nums){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int t=k%n;
        if(nums.size()<t){
            reverse(nums.begin(),nums.end());
            return ;
        }
        reverse(nums.begin(),nums.end());
        reverse_(0,t-1,nums);
        reverse_(t,n-1,nums);
        
        
    }
};