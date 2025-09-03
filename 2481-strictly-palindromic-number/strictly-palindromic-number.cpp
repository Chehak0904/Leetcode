class Solution {
public:
    string convert(int n,int b){
        string s="";
        while(n!=0){
            int digit=n%b;
            s+=digit+'0';
            n=n/b;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool isPalindrome(string s){
        int i=0, j=s.length();
        while(i<j){
            if(s[i++]!=s[j--]) return false; 
        }
        return false;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            string s=convert(n,i);
            if(!isPalindrome(s)) return false; 
        }
        return true;
        
    }
};