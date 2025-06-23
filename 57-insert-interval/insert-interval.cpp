class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        int idx = 0;
        while (idx<n && intervals[idx][0] <= newInterval[0]) {
            ans.push_back({intervals[idx][0], intervals[idx][1]});
            idx++;
        }
        if(!ans.empty() &&newInterval[0]<=ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],newInterval[1]);
        }
        else{
            ans.push_back(newInterval);
        }
        while(idx<n &&intervals[idx][0]<=ans.back()[1]){
            ans.back()[1]=max({ans.back()[1],intervals[idx][1]});
            idx++;

        }
        while(idx<n){
            ans.push_back({intervals[idx][0],intervals[idx][1]});
            idx++;
        }
        return ans;

    }
};