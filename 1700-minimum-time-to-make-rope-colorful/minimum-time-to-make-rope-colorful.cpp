class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int i=0;
        int j=1;
        int total=neededTime[0];
        int maxi=neededTime[0];
        int ans=0;
        while(j<colors.size()){
            if(colors[j]==colors[j-1]){
                total+=neededTime[j];
                maxi=max(maxi,neededTime[j]);
                j++;
            }
            else{
                if(j-i+1>1){
                    ans+=total-maxi;

                }
                total=neededTime[j];
                maxi=neededTime[j];
                i=j;
                j++;

            }

        } 
        ans+=total-maxi;
        return ans;   
    }
};