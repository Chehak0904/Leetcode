class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    void dfs(int i,int j,vector<vector<int>>&grid){
        grid[i][j] = -1; 
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(isSafe(nx,ny,grid.size(),grid[0].size()) && grid[nx][ny]==1){
                dfs(nx,ny,grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

       
        bool found=false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    found=true;
                    break;
                }
            }
        }

      
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    grid[i][j]=2; 
                }
            }
        }

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

       
        while(!q.empty()){
            auto [p,dist] = q.front(); q.pop();
            int x=p.first, y=p.second;

            for(int k=0;k<4;k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(!isSafe(nx,ny,n,m)) continue;

                if(grid[nx][ny] == -1){
                    return dist;
                }
                if(grid[nx][ny] == 0){
                    grid[nx][ny] = 2;            
                    q.push({{nx,ny}, dist+1});  
                }
                
            }
        }
        return -1; 
    }
};
