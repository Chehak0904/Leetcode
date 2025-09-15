class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=brokenLetters.size();
        unordered_set<char> st;
        for(char c:brokenLetters){
            st.insert(c);
        }
        int cnt=0;
        int i=0;
        while(i<text.size()){
            string s="";
            while(i<text.size() && text[i]!=' '){
                s+=text[i];
                i++;
            }
            i++;
            bool flag=true;
            for(int j=0;j<s.size();j++){
                if(st.find(s[j])!=st.end()){
                    flag=false;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};
