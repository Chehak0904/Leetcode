class Solution {
public:
    long long flowerGame(int n, int m) {
        long long on=n/2;
        long long en=(n+1)/2;
        long long om=m/2;
        long long em=(m+1)/2;
        return on*em+om*en;
        
    }
};