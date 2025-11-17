class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int>left(n);
        vector<int>right(n);
        int l=-1;
        for(int i=0;i<n;i++){
             left[i]=l;
             if(seats[i]==1){
                l=i;
             }
        }
        int r=-1;
        for(int i=n-1;i>=0;i--){
            right[i]=r;
            if(seats[i]==1){
                r=i;
            }
        }
        int ans =-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                int ld=(left[i]==-1)?n:i-left[i];
                int rd=(right[i]==-1)?n:right[i]-i;
                int d=min(ld,rd);
                if(d>maxi){
                    maxi=d;
                    ans=i;
                }
            }
        }
        return maxi;
        
    }
};