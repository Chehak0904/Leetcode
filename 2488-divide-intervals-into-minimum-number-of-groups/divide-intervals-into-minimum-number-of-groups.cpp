class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>mp;
        for(int i=0;i<intervals.size();i++){
            int u=intervals[i][0];
            int v=intervals[i][1];
            mp[u]+=1;
            mp[v+1]-=1;
        }
        int ans=0;
        int ps=0;
        for(auto it: mp){
            ps+=it.second;
            ans=max(ans,ps);
        }
        return ans;
    }
};