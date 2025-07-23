class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 0;
        int cnt=0;
        int i=0;
        int j=2;
        int cd=nums[1]-nums[0];
        while(j<n){
            if(nums[j]-nums[j-1]==cd){
                cnt+=j-2-i+1;
                j++;
            }
            else{
                i=j-1;
                cd=nums[j]-nums[i];
                j++;
            }

        }
        return cnt;
    }
};