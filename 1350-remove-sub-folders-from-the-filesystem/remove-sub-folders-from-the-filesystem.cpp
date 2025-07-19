class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(folder.begin(),folder.end());
        vector<string>result;
        for(int i=0;i<folder.size();i++){
            string dir=folder[i];
            bool flag=false;
            for(int i=0;i<dir.size();i++){
                if(dir[i]=='/' && st.find(dir.substr(0,i))!=st.end()){
                    flag=true;
                    break;
                }
                
            }
            if(!flag) result.push_back(dir);
        }
        return result;
        
        
    }
};