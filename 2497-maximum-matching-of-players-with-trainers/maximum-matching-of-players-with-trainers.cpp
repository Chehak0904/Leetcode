class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i=0,j=0;
        int cnt=0;
        int p=players.size(),t=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<p && j<t){
            if(players[i]<=trainers[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }

        }
        return cnt;
        
    }
};