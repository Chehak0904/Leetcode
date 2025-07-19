class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        vector<string>ans;
        sort(folder.begin(),folder.end());
        string prev=folder[0];
        ans.push_back(prev);
        int i=1;
        while(i<n){
            int l=prev.length();
            string curr=folder[i];
            int j=0;
            while(j<l && prev[j]==curr[j]){ j++;}
            if(j==l && curr[j]=='/'){
                i++;
            }
            else{
                ans.push_back(curr);
                prev=curr;
                i++;

            }
        }
        return ans;
    }
};