class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        string temp=words[0];
         ans.push_back(temp);
        sort(temp.begin(),temp.end());
        for(int i=1;i<words.size();i++){
            string w=words[i];
            sort(w.begin(),w.end());
            if(w==temp) continue;
            else{
                ans.push_back(words[i]);
                temp=w;
            }


        }
        return ans;
        
    }
};