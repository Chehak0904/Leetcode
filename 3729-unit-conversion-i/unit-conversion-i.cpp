class Solution {
public:
    int M=1e9+7;
    void dfs(int node,unordered_map<int,vector<pair<int,int>>>&mp,vector<int>&ans){
        for(auto it:mp[node]){
            int neigh=it.first;
            int weigh=it.second;
            ans[neigh]=(1LL*weigh*ans[node])%M;
            dfs(neigh,mp,ans);
        }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int units=conversions.size()+1;
        vector<int>ans(units,1);
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<conversions.size();i++){
            mp[conversions[i][0]].push_back({conversions[i][1],conversions[i][2]});
        }
        dfs(0,mp,ans);
        return ans;
        
    }
};