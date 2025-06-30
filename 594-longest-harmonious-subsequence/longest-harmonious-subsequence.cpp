class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int max_length=0;
        while(j<nums.size()){
            if(nums[j]-nums[i]<1){
                j++;
            }
            else if(nums[j]-nums[i]==1){
                max_length=max(max_length,j-i+1);
                j++;
            }
            else{
                i++;

            }
          
            
        }
        return max_length;

        
    }
};