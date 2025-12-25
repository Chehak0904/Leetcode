class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        int i=n-1;
        int cnt=0;
        long long ans=0;
        while(i>=0 && k--){
            int addition=max(0,happiness[i]-cnt);
            ans+=addition;
            i--;
            cnt++;
        }
        return ans;

        
    }
};