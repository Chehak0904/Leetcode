class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int u=intervals[i][0];
            int v=intervals[i][1];
            if(u<=end){
                end=max(end,v);
            }
            else{
                ans.push_back({start,end});
                start=u;
                end=v;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};