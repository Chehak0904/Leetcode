class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int minr=n,maxr=-1;
        int minc=m,maxc=-1;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==1){
                    minr=min(minr,r);
                    minc=min(minc,c);
                    maxr=max(maxr,r);
                    maxc=max(maxc,c);
                }
            }
        }
        return (maxr-minr+1)*(maxc-minc+1);

        
    }
};