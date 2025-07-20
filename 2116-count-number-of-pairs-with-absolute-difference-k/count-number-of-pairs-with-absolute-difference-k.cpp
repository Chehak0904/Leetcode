class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            cnt+=freq[nums[i]+k]+freq[nums[i]-k];
            freq[nums[i]]++;
        }
        return cnt;
        
    }
};