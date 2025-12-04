class Solution {
public:
    bool isPossible(int m,vector<int>&q,int n){
        for(int i=0;i<q.size();i++){
            int c=(q[i]+m-1)/m;
            n-=c;
            if(n<0){
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h=*max_element(quantities.begin(),quantities.end());
        int res=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(isPossible(m,quantities,n)){
                res=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
 
    }
};