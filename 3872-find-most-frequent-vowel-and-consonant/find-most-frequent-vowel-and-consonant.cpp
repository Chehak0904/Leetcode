class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='o' || c=='u' || c=='i';
    }
    int maxFreqSum(string s) {
        int maxiC=0;
        int maxiV=0;
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
            if(isVowel(c)) maxiV=max(maxiV,mp[c]);
            else maxiC=max(maxiC,mp[c]);
        }
        return maxiC+maxiV;
        
    }
};