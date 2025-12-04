class Solution {
public:
    bool isPossible(int m,vector<int>&piles,int h){
        long long cnt=0;
        for(int i=0;i<piles.size();i++){
              cnt+=piles[i]/m;
              if(piles[i]%m!=0){
                cnt++;
              }

        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini=1;
        int maxi=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(mini<=maxi){
            int m=(mini+maxi)/2;
            if(isPossible(m,piles,h)){
                ans=m;
                maxi=m-1;
            }
            else{
                mini=m+1;
            }
        }
        return ans;
        
    }
};