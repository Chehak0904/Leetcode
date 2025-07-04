class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0) cnt1++;
        }
        for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0) cnt2++;
        }
        long new_sum1=sum1+cnt1;
        long new_sum2=sum2+cnt2;
        if(new_sum1>new_sum2){
            if(cnt2==0){
                return -1;
            }
        }
        else if(new_sum1<new_sum2){
            if(cnt1==0){
                return -1;
            }
        }
        return max(new_sum1,new_sum2);
        
        
        
    }
};