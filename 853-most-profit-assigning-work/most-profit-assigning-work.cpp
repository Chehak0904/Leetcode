class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=worker.size();
        int m=difficulty.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int val=worker[i];
            int idx=-1;
            for(int j=0;j<m;j++){
                if(difficulty[j]<=val){
                    if(idx==-1 || profit[idx]<profit[j]){
                        idx=j;
                    }
                }
            }
            if(idx!=-1){
                ans+=profit[idx];
            }
        }
        return ans;    
    }
};
