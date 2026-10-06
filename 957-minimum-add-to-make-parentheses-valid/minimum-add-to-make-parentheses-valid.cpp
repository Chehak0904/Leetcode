class Solution {
public:
    int minAddToMakeValid(string s) {
        string stk="";
        int count=0;
        for(char ch:s){
            if(ch=='('){
                stk.push_back(ch);
            }
            else{
                if(stk.empty()){
                    count++;
                }
                else{
                  stk.pop_back();
                }
            }
        }
        while(!stk.empty()){
            count++;
            stk.pop_back();
        }
        return count;
        
    }
};