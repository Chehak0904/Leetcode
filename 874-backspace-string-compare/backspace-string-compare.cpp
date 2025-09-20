class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1="";
        string temp2="";
        for(char ch:s){
            if(ch=='#') {
                if(!temp1.empty()) temp1.pop_back();
            }
            else temp1.push_back(ch);
        }
        for(char ch:t){
            if(ch=='#') {
                if(!temp2.empty()) temp2.pop_back();
            }
            else temp2.push_back(ch);
        }
        return temp1==temp2;
        
    }
};