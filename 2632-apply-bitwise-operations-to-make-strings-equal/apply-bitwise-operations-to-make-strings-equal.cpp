class Solution {
public:
    bool makeStringsEqual(string s, string target) {
          bool check=true;
          for(int i=0;i<s.length();i++){
            if(s[i]!=target[i]){
                check=false;
                break;
            }
          }
          if(check) return true;
          bool check1=false,check2=false;
          for(char i:s){
            if(i=='1') check1=true;
          }
          for(char i:target){
            if(i=='1') check2=true;
          }
        return check1 && check2;
    }
};