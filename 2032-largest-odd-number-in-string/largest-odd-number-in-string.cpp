class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                idx=i;
                break;
            }

        }
        string res="";
        if(idx==-1) return res;
        for(int i=0;i<=idx;i++){
            res+=num[i];
        }
        return res;
        
    }
};