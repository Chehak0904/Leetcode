class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second==it.first){
                if(it.first>ans){
                    ans=it.first;
                }
            }
        }
        return ans;
    }
};