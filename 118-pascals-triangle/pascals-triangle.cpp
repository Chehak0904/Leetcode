class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev;
        prev.push_back(1);
        ans.push_back(prev);
        for(int i=0;i<numRows-1;i++){
            vector<int>curr;
            curr.push_back(1);
           for(int i=1;i<=prev.size()-1;i++){
            curr.push_back(prev[i-1]+prev[i]);
           }
           curr.push_back(1);
           prev=curr;
           ans.push_back(prev);

        }
        return ans;
        
    }
};