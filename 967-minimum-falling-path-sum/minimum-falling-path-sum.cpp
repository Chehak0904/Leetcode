class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>nxt(m);
        vector<int>curr(m);
        for(int j=0;j<m;j++){
            nxt[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int d=nxt[j];
                int l=INT_MAX;
                int r=INT_MAX;
                if(j-1>=0){
                    l=nxt[j-1];
                }
                if(j+1<=m-1){
                    r=nxt[j+1];
                }
                curr[j]= matrix[i][j] +min(l,min(d,r));

            }
            nxt=curr;
        }
        for(int i=0;i<m;i++){
            ans=min(ans,nxt[i]);
        }
        return ans;
        
        
    }
};