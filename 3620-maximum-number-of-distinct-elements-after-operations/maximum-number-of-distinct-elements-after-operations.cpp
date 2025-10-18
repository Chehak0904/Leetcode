class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int prev=INT_MIN,cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(prev==INT_MIN){
                int l=nums[i]-k;
                int r=nums[i]+k;
                cnt++;
                prev=l;
            }
            else{
                int l=nums[i]-k;
                int r=nums[i]+k;
                if(prev+1>r) continue;
                prev=max(prev+1,nums[i]-k);
                cnt++;
            }
        }
        return cnt;
        
    }
};