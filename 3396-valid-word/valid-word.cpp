class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='o' || ch=='e'|| ch=='i' || ch=='u');
    }
    bool isValid(string word) {
        int v=0;
        int c=0;
        int n=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a'&& word[i]<='z'){
                if(isVowel(word[i])) v++;
                else c++;
               
            }
            else if(word[i]>='A' && word[i]<='Z'){
                char ch=tolower(word[i]);
                
                if(isVowel(ch)) v++;
                else c++;
               
            }
            
            else if(word[i]>='0' && word[i]<='9'){
                n++;
            }
            else{
                return false;
            }
        }
        if(v>0&& c>0 &&v+c+n>=3)return true;
        return false;
            }
};