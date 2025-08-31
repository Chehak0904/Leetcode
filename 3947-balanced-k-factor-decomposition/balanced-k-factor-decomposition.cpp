class Solution {
public:
    int mindiff=INT_MAX;
    vector<int> bestSplit;
    void solve(vector<int>& divisors,int n,int k,vector<int>& ans){
        if(k==0 && n==1){
            int maxV=INT_MIN, minV=INT_MAX;
            for(int i:ans){
                maxV=max(maxV,i);
                minV=min(minV,i);
            }
            int diff=maxV-minV;
            if(mindiff>diff){
                mindiff=diff;
                bestSplit=ans;
            }
        }
        if(k<=0) return ;
        for(int d:divisors){
            if(n%d==0){
                ans.push_back(d);
                solve(divisors,n/d,k-1,ans);
                ans.pop_back();
            }
        }
        return ;
    }
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                divisors.push_back(i);
            }
        }
        vector<int> ans;
        solve(divisors,n,k,ans);
        if(!bestSplit.empty()){
            return bestSplit;
        }
        return {-1};
    }
};