class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<reservedSeats.size();i++){
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        int ans=(n-mp.size())*2;
        for(auto it:mp){
            vector<int>temp=it.second;
             bool left=true;
             bool right=true;
             bool middle=true;
            for(int i:temp){
                if(i>=2 && i<=5) left=false;
                if(i>=4 && i<=7) middle=false;
                if(i>=6 && i<=9) right=false;
            }
            if(left && right && middle) ans+=2;
            else if(left || right || middle) ans+=1;
        }
        return ans;
        
    }
};