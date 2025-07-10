class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>gap(n+1);
        gap[0]=startTime[0];
        gap[0]=startTime[0]-0;
        for(int i=1;i<n;i++){
            gap[i]=startTime[i]-endTime[i-1];
        }
        gap[n]=eventTime-endTime[n-1];
        vector<int>leftmax(n+1),rightmax(n+1);
        leftmax[0]=gap[0];
        for(int i=1;i<=n;i++){
            leftmax[i]=max(leftmax[i-1],gap[i]);
        }
        rightmax[n]=gap[n];
        for(int i=n-1;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],gap[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int dur=endTime[i]-startTime[i];
            int leftgap=0,rightgap=0;
            if(i-1>=0){
                leftgap=leftmax[i-1];
            }
            if(i+2<=n){
                rightgap=rightmax[i+2];

            }
            if(leftgap>=dur || rightgap>=dur){
                ans=max(ans,gap[i]+gap[i+1]+dur);
            }
            else{
                ans=max(ans,gap[i]+gap[i+1]);
            }
        }
        return ans;

       
    }
};