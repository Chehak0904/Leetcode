class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> preSum(n);
        int j=0;
        for(int i=n-1;i>=n-k;i--){
            preSum[j]=energy[i];
            j++;
        }
        int i=n-k-1;
        int l=0;
        while(i>=0){
            preSum[j]=energy[i]+preSum[l];
            j++,l++,i--;
        }
        int total=INT_MIN;
        for(int i=0;i<n;i++){
            total=max(total,preSum[i]);
        }
        return total;
    }
};