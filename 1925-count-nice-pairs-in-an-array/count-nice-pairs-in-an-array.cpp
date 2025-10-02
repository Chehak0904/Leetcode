class Solution {
public:
    int M=1e9+7;
    int rev(int num){
        string s=to_string(num);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i:nums){
            int diff=i-rev(i);
            if(mp.count(diff)){
                ans=(ans+mp[diff])%M;
            }
            mp[diff]++;
        }
        return ans;
        
    }
};