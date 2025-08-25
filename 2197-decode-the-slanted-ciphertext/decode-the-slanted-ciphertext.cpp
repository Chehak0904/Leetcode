class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans="";
        map<int,string>mp;
        int k=0;
        int n=encodedText.size();
        int m=n/rows;
        for(int i=0;i<rows;i++){
            for(int j=0;j<m;j++){
                mp[j-i].push_back(encodedText[k++]);
            }
        }
        for(auto &[it,st]:mp){
            if(it>=0){
                ans+=st;
            }

        }
        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        return ans;
        
    }
};