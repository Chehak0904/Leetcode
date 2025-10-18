class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<int>vec;
        for(auto &it:mp){
            vec.push_back(it.second);
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(k && i<vec.size()){
            int t=vec[i];
            if(k>=t){
               k=k-t;
               vec[i]=0;
            }
            i++;
        }
        int cnt=0;
        for(int i:vec){
            if(i>0) cnt++;
        }
        return cnt;
    }
};