class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long totalCost=0;
        for(int i:cost){
            totalCost+=i;
        }
        unordered_map<char,long long>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]+=cost[i];
        }
        long long mini=LLONG_MAX;
        for(auto it:mp){
            mini=min(mini,totalCost-it.second);
        }
        return mini;

        
    }
};