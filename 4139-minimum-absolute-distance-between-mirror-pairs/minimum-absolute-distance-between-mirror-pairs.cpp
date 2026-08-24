class Solution {
public:
    int reverse(int num){
        int revnum=0;
        while(num>0){
            int d=num%10;
            revnum=revnum*10+d;
            num=num/10;
        }
        return revnum;
    }
    int ans=INT_MAX;
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(mp.count(num)){
               ans=min(ans,abs(i-mp[num]));
            }
            mp[reverse(nums[i])]=i;
        }
        if(ans==INT_MAX) return -1;
        else return ans;
        
    }
};