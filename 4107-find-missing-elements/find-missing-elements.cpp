class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        int i=1;
        while(i<n){
            if(nums[i]!=prev+1){
                ans.push_back(prev+1);
                prev++;
            }
            else{
                prev=nums[i];
                i++;
            }
        }
        return ans;
        

        
    }
};