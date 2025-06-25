class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>diff_arr(nums.size(),0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            diff_arr[l]-=1;
            if(r+1<nums.size()){
                diff_arr[r+1]+=1;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=diff_arr[i];
            if(nums[i]+sum>0){
                return false;
            }
        }
        return true;

        
    }
};