class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        unordered_set<int> st;
        for(int f:friends){
            st.insert(f);
        }
        vector<int> ans;
        for(int o:order){
            if(st.find(o)!=st.end()){
                ans.push_back(o);
            }
        }
        return ans;
    }
};