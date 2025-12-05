class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int Tsum=0;
        for(int i=0;i<nums.size();i++){
            Tsum+=nums[i];
        }
        int lsum=0;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            lsum+=nums[i];
            int rsum=Tsum-lsum;
            if(abs(lsum-rsum)%2==0){
                  cnt++;
            }

        }
        return cnt;
        
    }
};