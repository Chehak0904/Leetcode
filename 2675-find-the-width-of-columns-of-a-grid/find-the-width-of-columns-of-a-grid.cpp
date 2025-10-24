class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid[0].size();
        vector<int>vec(m);
        for(int j=0;j<m;j++){
            int maxi=-1;
            for(int i=0;i<grid.size();i++){
                int l=to_string(grid[i][j]).length();
                maxi=max(maxi,l);
            }
            vec[j]=maxi;
        }
        return vec;
        
    }
};