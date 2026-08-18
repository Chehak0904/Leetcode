class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>count;
        for(int num:nums){ count[num]++;}
        if(k==n){
           return *max_element(nums.begin(),nums.end());
        }
        else if(k==1){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(count[nums[i]]==1) maxi=max(maxi,nums[i]);
            }
            if(maxi==INT_MIN) return -1;
            return maxi;
        }
        else{
             int i=0,j=n-1;
             if(count[nums[i]] == 1 && count[nums[j]] == 1){
                return max(nums[i],nums[j]);
             }
             else if(count[nums[i]]==1){
                return nums[i];
             }
             else if(count[nums[j]]==1) return nums[j];
             else return -1;
        }
    }
};