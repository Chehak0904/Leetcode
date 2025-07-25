class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int maxi=INT_MIN;
        for(int num:nums){
            if(num>=0){
                st.insert(num);
            }
            maxi=max(num,maxi);//store highest neg
        }
        if(st.empty())return maxi;
        int res=0;
        for(int s:st){
            res+=s;
        }
        return res;
    }
};