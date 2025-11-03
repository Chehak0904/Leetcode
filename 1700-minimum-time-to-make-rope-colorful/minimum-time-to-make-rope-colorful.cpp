class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum=neededTime[0];
        int maxi=neededTime[0];
        int ans=0;
        for(int i=1;i<colors.length();i++){
            if(colors[i]==colors[i-1]){
                maxi=max(maxi,neededTime[i]);
                sum+=neededTime[i];
            }
            else{
                ans+=(sum-maxi);
                maxi=neededTime[i];
                sum=neededTime[i];

            }
        }
        ans+=(sum-maxi);
        return ans;
    }
};