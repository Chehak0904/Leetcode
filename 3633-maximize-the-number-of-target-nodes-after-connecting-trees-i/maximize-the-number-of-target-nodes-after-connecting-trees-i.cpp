class Solution {
public: 
    int bfs(const unordered_map<int, vector<int>>& adj, int start, int k){
        vector<bool> visited(adj.size()+1,false);
            queue<pair<int,int>> q;
            visited[start]=true;
            q.push({start,0});
            int cnt=0;
            while(!q.empty()){
                int u=q.front().first;
                int depth=q.front().second;
                cnt++;
                q.pop();
                if(depth<k){
                    for(int v:adj.at(u)){
                       if(!visited[v]){
                        visited[v]=true;
                        q.push({v,depth+1});
                       }
                    }
                }    
            }
            return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m =edges2.size()+1;
        vector<int> ans(n,1);
        if(k==0){
            return ans;
        }
        unordered_map<int,vector<int>> adj1;
        unordered_map<int,vector<int>> adj2;
        for(int i=0;i<n-1;i++){
            int u=edges1[i][0];
            int v=edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i=0;i<m-1;i++){
            int u=edges2[i][0];
            int v=edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int maxi=0;
        for(int i=0;i<m;i++){
            maxi = max(maxi, bfs(adj2, i, k - 1));;
        }
        
        for(int i=0;i<n;i++){
            ans[i] = bfs(adj1, i, k) + maxi;
        }
        return ans;
    }
};