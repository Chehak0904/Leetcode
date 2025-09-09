class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>mp;
        while(n!=0){
            int digit=n%10;
            mp[digit]++;
            n=n/10;
        }
        int mini=INT_MAX;
        int ans=-1;
        for(auto it:mp){
            if(it.second<mini){
                mini=it.second;
                ans=it.first;
            }
            else if(it.second==mini){
                ans=min(ans,it.first);
            }
        }
        return ans;


        
    }
};