class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        string ans="";
        long long ts=0;
        for(int i=n-1;i>=0;i--){
            ts+=shifts[i];
            char ch=(s[i]-'a'+ts)%26+'a';
            ans.push_back(ch);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};