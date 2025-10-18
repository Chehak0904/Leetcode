class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<pair<int,int>>vec;
        for(auto it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            while(vec[i].first!=0 && k>0){
                vec[i].first--;
                k--;
                if(k==0) break;
            }
        }
        int cnt=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first>0) cnt++;
        }
        return cnt;
    }
};