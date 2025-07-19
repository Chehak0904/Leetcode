class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;
        priority_queue<int> pq;
        vector<long long> preSum(N);
        long long sum=0;
        for(int i=0;i<N-n  ;i++){
            sum+=nums[i];
            pq.push(nums[i]);
            if(pq.size()>n){
                sum-=pq.top();
                pq.pop();
            }
            preSum[i]=sum;
        }
        priority_queue<int,vector<int>,greater<>> pq2;
        vector<long long> sufSum(N);
        sum=0;
        for(int i=N-1;i>=n;i--){
            sum+=nums[i];
            pq2.push(nums[i]);
            if(pq2.size()>n){
                sum-=pq2.top();
                pq2.pop();
            }
            sufSum[i]=sum;
        }
        long long ans=LLONG_MAX;
        for(int i=n-1;i<N-n;i++){
            ans=min(ans,preSum[i]-sufSum[i+1]);
        }
        return ans;
    }
};