class Solution {
public: 
    int fun(char s,char e, int i,vector<string>& words,vector<vector<vector<int>>> &dp){
        if(i==words.size()) return 0;
        char f=words[i][0];
        char l=words[i].back();
        int len=words[i].length();
        if(dp[s-'a'][e-'a'][i]!=-1) return dp[s-'a'][e-'a'][i];        
        int a=(e==f)? fun(s,l,i+1,words,dp)+len-1: fun(s,l,i+1,words,dp)+len;
        
        int b=(l==s)?fun(f,e,i+1,words,dp)+len-1: fun(f,e,i+1,words,dp)+len;
        return dp[s-'a'][e-'a'][i]= min(a,b);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size();
        string prev=words[0];
        vector<vector<vector<int>>> dp(26,vector<vector<int>>(26,vector<int>(n,-1)));
        return prev.size()+ fun(prev[0],prev.back(),1, words,dp);
    }
};