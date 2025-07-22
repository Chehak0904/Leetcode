class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0;
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            while(mp.size()<j-i+1){
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            ans=max(ans,sum);
            j++;

        }
        return ans;
        
    }
};