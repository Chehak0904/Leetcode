class Solution {
public:
    int solve(unordered_map<int,vector<int>>&mp,int node,int &count,int parent){

        bool flag=true;
        int val=-1;
        int sz=0;
        for(auto it:mp[node]){
            if(it==parent) continue;
            int t=solve(mp,it,count,node);
            if(val==-1) val=t;
            else{
                if(val!=t){
                    flag=false;
                }
            }
            sz+=t;

        }
        if(flag) count++;
        return sz+1;

       
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int cnt=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
               int u=edges[i][0];
               int v=edges[i][1];
               mp[u].push_back(v);
               mp[v].push_back(u);
        }
        int t=solve(mp,0,cnt,-1);
        return cnt;


        
    }
};