class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()!=2){
            string temp="";
            for(int i=0;i<s.length()-1;i++){
                int d=(s[i]+s[i+1])%10;
                temp+=d;
            }
            s=temp;
        }
        return s[0]==s[1];
        
    }
};