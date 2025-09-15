class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans=INT_MAX;
        for(int i=0;i<tasks.size();i++){
            vector<int>vec=tasks[i];
            int a=vec[0];
            int b=vec[1];
            ans=min(ans,a+b);
        }
        return ans;
    }
};