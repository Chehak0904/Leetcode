class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.length();i++){
            if(mp.count(order[i])){
                int cnt=mp[order[i]];
                while(cnt--){
                    ans+=order[i];
                }
                mp.erase(order[i]);
            }
        }
        for(auto it:mp){
            int cnt=it.second;
            while(cnt--){
                ans+=it.first;
            }
        }
        return ans;
    }
};