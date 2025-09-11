class Solution {
public:
    bool isVowel(char ch){
        char c=tolower(ch);
        return c=='a' || c=='u'|| c=='o'|| c=='e' || c=='i';
    }
    string sortVowels(string s) {
        vector<pair<char,int>>v;
        for(char ch:s){
            if(isVowel(ch)){
                v.push_back({(int)ch,ch});
            }
        }
        int k=0;
        sort(v.begin(),v.end());
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=v[k].second;
                k++;
            }
        }
        return s;
    }
};