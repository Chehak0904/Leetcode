class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0;
        for(char ch:s){
            if(ch=='('){
                count++;
                if(count>1) ans.push_back(ch);
            }else{
                if(count>1) ans.push_back(ch);
                count--;
            }
        }
        return ans;  
    }
};