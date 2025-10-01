class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int empty = 0;
        int ans = 0;
        while (filled >= 1) {
            ans += filled;
            empty += filled;
            filled = empty / numExchange;
            empty = empty % numExchange;
        }
        return ans;
    }
};