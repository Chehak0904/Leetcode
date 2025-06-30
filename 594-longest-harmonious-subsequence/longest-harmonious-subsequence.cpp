class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_length=0;
        unordered_map<int,int>cnt;
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
        }
        for(auto it:cnt){
            if(cnt.find(it.first+1)!=cnt.end()){
                max_length=max(max_length,cnt[it.first]+cnt[it.first+1]);
            }
        }
        return max_length;

        
    }
};