class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        res+=s[0];
        res+=s[1];
        if(s.length()==1 || s.length()==2) return s;
        for(int i=2;i<s.length();i++){
            char ch=s[i];
            if(ch==res[res.length()-1] && ch==res[res.length()-2]){
                    continue;
            }
            else{
                res+=s[i];
            }
        }
        return res;
        
    }
};