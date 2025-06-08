class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n);
        for(int i=0;i<n;i++){
            group[i]=i;
        }
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                group[i+1]=group[i];

            }

        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(group[u]==group[v]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }

        }
        return ans;
    }
};