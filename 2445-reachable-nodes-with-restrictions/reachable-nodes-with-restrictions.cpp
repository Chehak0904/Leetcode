class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&mp,vector<bool>&visited,int &cnt){
             
            cnt++;
            visited[node]=true; 
            for(auto it:mp[node]){
                if(!visited[it]){
                    dfs(it,mp,visited,cnt);
                }
            }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0;i<restricted.size();i++){
            visited[restricted[i]]=true;
        }
        dfs(0,mp,visited,cnt);
        return cnt;

    }
};