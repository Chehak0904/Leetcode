class Solution {
public:
    bool dfs(int node,int dest,unordered_map<int,vector<int>>&mp,vector<int>&visited){
        if(node==dest){
            return true;
        }
        visited[node]=true;
        for(auto it:mp[node]){
            if(!visited[it]){
                 if(dfs(it,dest,mp,visited)){
                    return true;
                 }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,false);
        return dfs(source,destination,mp,visited);
    }
};