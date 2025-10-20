class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=k;i<=100+k;i+=k){
            if(st.find(i)==st.end()) return i;
        }
        return -1;
        
    }
};