class Solution {
public:
    string largestGoodInteger(string num) {
        int digit=-1;
        for(int i=2;i<num.length();i++){
            if(num[i]-'0'>digit && num[i]==num[i-1] && num[i]==num[i-2]){
                digit=num[i]-'0';
            }
        }
        string res="";
        if(digit==-1) return res;
        for(int i=0;i<3;i++){
            res+=(digit)+'0';
        }
        return res;
        
    }
};