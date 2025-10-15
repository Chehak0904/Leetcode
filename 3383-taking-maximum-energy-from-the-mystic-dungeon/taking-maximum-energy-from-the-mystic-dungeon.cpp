class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>prefix(n);
        int j=0;
        for(int i=n-1;i>=n-k;i--){
            prefix[j]=energy[i];
            j++;
        }
        int l=0;
        int i=n-k-1;
        while(i>=0){
            prefix[j]=energy[i]+prefix[l];
            l++;
            j++;
            i--;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,prefix[i]);
        }
        return maxi;
        
    }
};