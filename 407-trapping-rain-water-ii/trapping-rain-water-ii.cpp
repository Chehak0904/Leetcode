class Solution {
public:
    typedef pair<int,pair<int,int>>pp;
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<pp,vector<pp>,greater<>>pq;
        for(int j=0;j<n;j++){
            visited[0][j]=true;
            visited[m-1][j]=true;
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[m-1][j],{m-1,j}});
        }
         for(int i=1;i<m-1;i++){
            visited[i][0]=true;
            visited[i][n-1]=true;
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
        }
        int ans=0;
        while(!pq.empty()){
            int height=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj]){
                    ans+=max(0,height-heightMap[ni][nj]);
                    pq.push({max(height,heightMap[ni][nj]),{ni,nj}});
                    visited[ni][nj]=true;
                }
            }
        }

        return ans;
    }
};