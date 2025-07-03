class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string temp=s;
            for(int i=0;i<temp.length();i++){
                temp[i]=((temp[i]-'a')+1)%26+'a';

            }
            s+=temp;

        }
        return s[k-1];
        
    }
};