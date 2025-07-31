class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>res;
        unordered_set<int>prev;
        for(int num:arr){
            unordered_set<int>curr;
            curr.insert(num);
            for(auto it:prev){
                curr.insert(num|it);
            }
            res.insert(curr.begin(),curr.end());
            prev=curr;
        }
        return res.size();

        
    }
};