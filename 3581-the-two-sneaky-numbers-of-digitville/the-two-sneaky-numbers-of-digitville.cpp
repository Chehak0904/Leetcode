class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>st;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()) st.insert(nums[i]);
            else ans.push_back(nums[i]);
        }
        return ans;
        
    }
};