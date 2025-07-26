class Solution {
public:
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj,int& cnt){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[abs(it)]){
                if(it>0) cnt++;
                dfs(abs(it),visited,adj,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool>visited(n);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
           adj[b].push_back(-a); 
        }
        int cnt=0;
        dfs(0,visited,adj,cnt);
        return cnt;
        
    }
};