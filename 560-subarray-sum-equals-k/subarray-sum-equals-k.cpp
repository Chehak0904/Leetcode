class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> vec(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            vec[i]=sum;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vec[i]==k){
                ans++;
            }
            if(mp.find(vec[i]-k)!=mp.end()){
                ans+=mp[vec[i]-k];
            }
            mp[vec[i]]++;
        }
        return ans;
    }
};