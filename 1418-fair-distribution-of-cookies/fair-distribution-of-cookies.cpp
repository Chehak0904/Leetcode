class Solution {
public:
    int func(int idx,vector<int>&cookies,vector<int>&children){
        if(idx>=cookies.size()) return *max_element(children.begin(),children.end());
        int ans=INT_MAX;
        for(int j=0;j<children.size();j++){
            children[j]+=cookies[idx];
            ans=min(ans,func(idx+1,cookies,children));
            children[j]-=cookies[idx];

        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>ch(k,0);
        return func(0,cookies,ch);
    }
};