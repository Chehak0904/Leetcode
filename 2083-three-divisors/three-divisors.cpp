class Solution {
public:
    bool isThree(int n) {
        if(n==1) return false;
        bool isPerfect=false;
        //time complexity->sqrt of n;
        int num=-1;
        for(int i=1;i*i<=n;i++){
            if(i*i==n){
                isPerfect=true;
                num=i;
            }
        }
        if(!isPerfect) return false;
        // time complexity->sqet(n)
        for(int i=2;i*i<=num;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
        
    }
};