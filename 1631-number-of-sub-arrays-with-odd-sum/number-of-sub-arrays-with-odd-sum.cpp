class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // need to track even or odd sum before that
        int even_count=1;
        int odd_count=0;
        int sum=0;
        int ans=0;
        int mod=1000000007;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                ans=(ans+odd_count)%mod;
                even_count++;
            }
            else{
                ans=(ans+even_count)%mod;
                odd_count++;
            }

        }
        return ans;
        
        
    }
};