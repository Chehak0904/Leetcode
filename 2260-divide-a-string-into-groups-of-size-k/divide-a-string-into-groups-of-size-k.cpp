class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp="";
        for(int i=0;i<s.length();i++){
            temp.push_back(s[i]);
            if(temp.length()==k){
                ans.push_back(temp);
                temp="";
            }
        }
        while(!temp.empty() && temp.length()!=k){
            temp.push_back(fill);

        }
        if(!temp.empty()){
            ans.push_back(temp);
        }
        return ans;
    }
};