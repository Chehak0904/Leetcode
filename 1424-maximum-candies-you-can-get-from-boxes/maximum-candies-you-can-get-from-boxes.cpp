class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool> AvailableBoxes(n,false), AvailableKeys(n,false), visited(n,false);
        queue<int> q;
        for(int box:initialBoxes){
            if(status[box]==1){
                q.push(box);
                visited[box]=true;
            }
            AvailableBoxes[box]=true;
        }
        int cnd=0;
        while(!q.empty()){
            int b=q.front();
            q.pop();
            cnd+=candies[b];
            for(int k:keys[b]){
                if(!AvailableKeys[k]){
                    AvailableKeys[k]=true;
                    if(AvailableBoxes[k] && !visited[k]){
                        q.push(k);
                        visited[k]=true;
                    }
                }
            }
            for(int c: containedBoxes[b]){
                AvailableBoxes[c]=true;
                if((AvailableKeys[c] || status[c]==1) && !visited[c]){
                    q.push(c);
                    visited[c]=true;
                }
            }
        }
        return cnd;
    }
};