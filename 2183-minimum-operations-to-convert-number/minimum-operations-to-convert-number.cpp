class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int>vis(1001,0);
        queue<int>q;
        q.push(start);
        vis[start]=-1;
        int op=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
               int num=q.front();
               q.pop();
               if(num==goal) return op;
               for(int i=0;i<nums.size();i++){
                   vector<int>nxt;
                   nxt.push_back(num+nums[i]);
                   nxt.push_back(num-nums[i]);
                   nxt.push_back(num^nums[i]);
                   for(auto it:nxt){
                     if (it == goal) return op + 1;
                    if(it<0 || it>1000 || vis[it]) continue;
                    vis[it]=1;
                    q.push(it);
                   }
               } 
               

            }
            op++;
           
        }
        return -1;
        
    }
};