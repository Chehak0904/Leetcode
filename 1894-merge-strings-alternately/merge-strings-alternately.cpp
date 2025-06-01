class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        string temp="";
        int i=0,j=0;
        while(i<n1 && j<n2){
            temp.push_back(word1[i]);
            i++;
            temp.push_back(word2[j]);
            j++;

        }
        while(i<n1){
            temp.push_back(word1[i]);
            i++;
        }
        while(j<n2){
            temp.push_back(word2[j]);
            j++;
        }
        return temp;

        
    }
};