class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,long long &sum){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(grid[i][j]<=0) return;
        sum+=grid[i][j];
        grid[i][j]*=-1;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int nx=i+dir[k].first;
            int ny=j+dir[k].second;
            dfs(nx,ny,grid,sum);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long sum=0;
                    dfs(i,j,grid,sum);
                    if(sum%k==0)cnt++;
                }
            }
        }
        return cnt;
        
        
    }
};