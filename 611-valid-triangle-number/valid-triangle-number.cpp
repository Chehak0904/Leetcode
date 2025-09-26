class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int k=n-1;
        int ans=0;
        while(k>=2){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    ans+=j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
            k--;

        }
        return ans;
        
    }
};