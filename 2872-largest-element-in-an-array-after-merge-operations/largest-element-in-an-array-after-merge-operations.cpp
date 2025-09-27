class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=nums[n-1];
        vector<long long>vec(n);
        for(int i=0;i<vec.size();i++){
            vec[i]=nums[i];
        }
        for(int i=n-2;i>=0;i--){
            if(vec[i]<=vec[i+1]){
                vec[i]=vec[i]+vec[i+1];
                
            }
            ans=max(ans,vec[i]);
        }
        return ans;
    }
};