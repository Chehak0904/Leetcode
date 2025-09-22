class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi;
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
            maxi=max(maxi,mp[num]);
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second==maxi){
                cnt++;
            }
        }
        return cnt*maxi;
        
    }
};