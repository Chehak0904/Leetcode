class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cnt=0;
        sort(meetings.begin(),meetings.end());
        cnt+=meetings[0][0]-1;
        int end=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]<=end){
                end=max(end,meetings[i][1]);
            }
            else{
                cnt+=meetings[i][0]-end-1;
                end=meetings[i][1];
            }
        }
        cnt+=days-end;
        return cnt;
        
    }
};