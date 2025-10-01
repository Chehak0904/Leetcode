class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int empty=0;
        int ans=0;
        while(!(full==0 && empty/numExchange==0)){
            ans+=full;
            int curr_empty=full;
            int total_empty=curr_empty+empty;
            full=total_empty/numExchange;
            empty=total_empty%numExchange;
        }
        return ans;
        
    }
};