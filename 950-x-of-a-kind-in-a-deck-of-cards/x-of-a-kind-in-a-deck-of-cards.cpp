class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(int i=0;i<deck.size();i++){
            mp[deck[i]]++;
        }
        int g=0;
        for(auto it:mp){
            g=__gcd(g,it.second);
        }
        if(g==1)return false;
        return true;

        
    }
};