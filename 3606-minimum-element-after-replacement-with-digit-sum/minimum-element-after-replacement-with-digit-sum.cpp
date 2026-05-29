class Solution {
public:
    int sum(int n){
        int s=0;
        while(n!=0){
            s+=(n%10);
            n=n/10;

        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int num:nums){
            int s_sum=sum(num);
            mini=min(mini,s_sum);
        }
        return mini;
        
    }
};