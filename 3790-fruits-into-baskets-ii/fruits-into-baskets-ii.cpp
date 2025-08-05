class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]!=-1 && baskets[j]>=fruits[i]){
                    cnt++;
                    baskets[j]=-1;
                    break;
                }
            }
        }
    
        return n-cnt;
        
    }
};