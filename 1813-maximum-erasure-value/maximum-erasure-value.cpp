class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int ans=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            mp[nums[j]]++;
            while(mp.size()<j-i+1){
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans=max(ans,sum);
            j++;

        }
        return ans;
        
    }
};