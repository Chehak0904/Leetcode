class Solution {
public:
    bool check(int n){
        while(n!=0){
            int d=n%10;
            if(d==0) return false;
            n=n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<=n/2;i++){
            int a=i,b=n-i;
            if(check(a)&& check(b)){
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }
        return ans;
        
    }
};