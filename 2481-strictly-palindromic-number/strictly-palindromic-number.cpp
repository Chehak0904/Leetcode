class Solution {
public:
    string baseVal(int n,int b){
        string val="";
        while(n>0){
            val=(char)(n%b +'0')+val;
            n=n/b;
        }
        return val;
    }
    bool isPalindrome(string val){
        int len=val.length();
        int l=0, r=len-1;
        while(l<=r){
            if(val[l]==val[r]){
                l++, r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int b=2;b<=n-2;b++){
            string val=baseVal(n,b);
            if(!isPalindrome(val)){
                return false;
            }
        }
        return true;
    }
};