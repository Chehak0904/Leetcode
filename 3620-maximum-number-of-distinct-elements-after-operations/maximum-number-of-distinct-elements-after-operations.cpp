class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int last=INT_MIN;
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l=nums[i]-k;
            int r=nums[i]+k;
            last=max(last,l);
            if(last<=r){
               cnt++;
               last++;
            }
        }
        return cnt;
        
    }
};