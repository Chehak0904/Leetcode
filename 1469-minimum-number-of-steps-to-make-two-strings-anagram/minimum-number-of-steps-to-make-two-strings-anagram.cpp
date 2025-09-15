class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int cnt=0;
        for(char c:s) mp[c]++;
        for(char c:t){
            if(!mp.count(c)) cnt++;
            else{
                mp[c]--;
                if(mp[c]==0) mp.erase(c);
            }
        }
        return cnt;
        
    }
};