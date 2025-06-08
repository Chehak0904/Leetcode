class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>indeg(n,0);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<graph.size();i++){

            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);

            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};