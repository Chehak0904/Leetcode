class Solution {
public:
    void backtrack(int str,int n,int k,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==k && n==0) {
            ans.push_back(temp);
        }
        if(temp.size()==k && n>0) return ;
        if(temp.size()!=k && n<=0) return ;
        for(int j=str;j<=9;j++){
            temp.push_back(j);
            backtrack(j+1,n-j,k,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        backtrack(1,n,k,temp,ans);
        return ans;
        
    }
};