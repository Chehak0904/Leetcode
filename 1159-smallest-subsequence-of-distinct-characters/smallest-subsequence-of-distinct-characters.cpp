class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>lastPos(26);
        for(int i=0;i<s.length();i++){
            lastPos[s[i]-'a']=i;
        }
        vector<bool>v(26,false);
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(v[ch-'a']) continue;
            while(!ans.empty() && ans.back()>ch &&lastPos[ans.back()-'a']>i){
                v[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            v[ch-'a']=true;
        }
        return ans;
        
    }
};