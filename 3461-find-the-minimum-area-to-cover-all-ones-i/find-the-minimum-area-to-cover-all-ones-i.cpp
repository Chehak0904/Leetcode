class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int minr=n,maxr=-1;
        int minc=m,maxc=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r=i;
                int c=j;
                if(grid[r][c]==1){
                    if(r<minr) minr=r;
                    if(r>maxr) maxr=r;
                    if(c<minc) minc=c;
                    if(c>maxc)
                        maxc=c;  
                }
            }
        }
        return (maxr-minr+1)*(maxc-minc+1);

        
    }
};