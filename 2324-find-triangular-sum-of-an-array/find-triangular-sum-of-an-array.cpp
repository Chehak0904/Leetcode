class Solution {
public:
    int triangularSum(vector<int>& nums) {

       vector<int>prev=nums;
        while(prev.size()!=1){
            vector<int>curr(prev.size()-1);
            for(int i=0;i<curr.size();i++){
                curr[i]=(prev[i+1]+prev[i])%10;
            }
            prev=curr;
        }
        return prev[0];
        
    }
};