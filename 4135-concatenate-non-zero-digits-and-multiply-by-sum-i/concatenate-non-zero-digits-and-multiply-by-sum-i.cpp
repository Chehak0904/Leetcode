class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        long long sum=0;
        int m=1;
        while(n>0){
            int digit=n%10;
            if(digit!=0){
                num=digit*m+num;
                sum+=digit;
                m=m*10;
            }
            n=n/10;
        }
        long long ans=num*sum;
        return ans;
        
        
    }
};