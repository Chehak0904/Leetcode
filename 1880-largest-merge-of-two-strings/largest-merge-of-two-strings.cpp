class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        string temp="";
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(word1[i]>word2[j]){
                temp+=word1[i];
                i++;
            }
            else if(word2[j]>word1[i]){
                temp+=word2[j];
                j++;
                
            }else{
                if(word1.substr(i)>word2.substr(j)){
                    temp+=word1[i++];
                }
                else{
                    temp+=word2[j++];
                }
            }
        }
        while(i<n1){
            temp+=word1[i++];
        }
        while(j<n2){
            temp+=word2[j++];
            
        }
        return temp;
        
    }
};