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
        k = k%n;
       if(n==0)return ;
       if(k==0) return ;
        reverse(nums.begin(),nums.end());
        reverse_(0,k-1,nums);
        reverse_(k,n-1,nums);
        
        
    }
};