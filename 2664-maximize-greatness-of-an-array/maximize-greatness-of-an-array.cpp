class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]>nums[i]){
                cnt++;
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        return cnt;
        
    }
};