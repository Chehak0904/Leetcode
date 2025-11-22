class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int t=nums[i]%3;
            if(t)cnt++;
        }
        return cnt;
        
    }
};