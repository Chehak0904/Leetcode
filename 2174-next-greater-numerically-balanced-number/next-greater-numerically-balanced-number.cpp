class Solution {
public:
    bool check(int n){
        string s=to_string(n);
        unordered_map<int,int>mp;
        for(auto i:s){
            mp[i-'0']++;
        }
        for(auto it:mp){
            if(it.first!=it.second) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(true){
            if(n>=1e6) return 1224444;
            if(check(n+1)) return n+1;
            n++;
        }
        return -1;
        
    }
};