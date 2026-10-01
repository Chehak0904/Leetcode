class Solution {
public:
    bool isValid(string str) {
        string s="";
        for(char ch:str){
            if(ch=='(' || ch=='{' || ch=='['){
                s.push_back(ch);
            }
            else if(!s.empty()&&((ch==')' && s.back()=='(')||(ch==']' && s.back()=='[')||(ch=='}' && s.back()=='{'))){
                s.pop_back();

            }else{
                return false;
            }
        }
        return (s.empty());
        
    }
};