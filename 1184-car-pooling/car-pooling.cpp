class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        for(int i=0;i<trips.size();i++){
            int numP=trips[i][0];
            int s=trips[i][1];
            int e=trips[i][2];
            mp[s]+=numP;
            mp[e]-=numP;
        }
        int sum=0;
        for(auto it:mp){
            sum+=it.second;
            if(sum>capacity){
                return false;
            }
        }
        return true;
    }
};