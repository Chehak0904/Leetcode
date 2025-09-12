class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u';
    }
    bool doesAliceWin(string s) {
        int cnt=0;
        for(auto ch:s){
            if(isVowel(ch)) cnt++;
        }
        if(cnt==0) return false;
        if(cnt%2!=0) return true;
        else return true;    
    }
};