class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(i);
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq2;
        int m=meetings.size();
        vector<int> vec(n,0);
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<m;i++){
            long long s= meetings[i][0];
            long long e=meetings[i][1];
            while(!pq2.empty() && pq2.top().first<=s){
                pq.push(pq2.top().second);
                pq2.pop();
            }
            if(!pq.empty()){
                int t=pq.top();
                pq.pop();
                pq2.push({e,t});
                vec[t]++;
            }
            else{
                long long pe=pq2.top().first;
                int t=pq2.top().second;
                long long dur=e-s;
                
                pq2.pop();
                pq2.push({pe+dur,t});
                vec[t]++;
            }
        }
        int ans=0, idx=-1;
        for(int i=0;i<n;i++){
            if(vec[i]>ans){
                ans=vec[i];
                idx=i;
            }
        }
        return idx;

    }
};