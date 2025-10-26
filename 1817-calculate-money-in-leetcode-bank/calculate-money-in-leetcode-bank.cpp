class Solution {
public:
    int totalMoney(int n) {
        int i=n%7;
        int j=n/7;
        int ans=0;
        ans+=(j*(56+(j-1)*7))/2;
        int s=j+1;
        while(i--){
            ans+=s++;
        }
        return ans;

      
    }
};