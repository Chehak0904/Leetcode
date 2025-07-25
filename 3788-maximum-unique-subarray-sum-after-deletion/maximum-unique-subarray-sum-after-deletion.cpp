class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int neg_count=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                mp[nums[i]]++;
            }
            else{
                neg_count++;
                maxi=max(maxi,nums[i]);

            }
        }
        int sum=0;
        for(auto it:mp){
            sum+=it.first;

        }
        if(neg_count==nums.size()){
            return maxi;
        }
        return sum;
        
    }
};