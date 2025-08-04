class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>0 && baskets[j]>=fruits[i]){
                    baskets[j]*=-1;
                    break;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<baskets.size();i++){
            if(baskets[i]>0) cnt++;
        }
        return cnt;
        
    }
};