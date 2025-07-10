class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gap(n+1);
        gap[0]=startTime[0];
        for(int i=1;i<n;i++){
            gap[i]=startTime[i]-endTime[i-1];
        }
        gap[n]=eventTime-endTime[n-1];
        
        int sum=0;
        for(int i=0;i<=n && i<=k;i++){
            sum+=gap[i];
        }
        int ans=sum;
        int i=0, j=k;
        while(j<n){
            sum-=gap[i++];
            sum+=gap[++j];
            ans=max(ans,sum);
        }
        return ans;
    }
};