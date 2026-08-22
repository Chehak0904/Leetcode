class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        long long product=1;
        long long sum=0;
        while(num>0){
            int digit=num%10;
            sum+=digit;
            product*=digit;
            num=num/10;
        }
        return n%(product+sum)==0;
        
    }
};