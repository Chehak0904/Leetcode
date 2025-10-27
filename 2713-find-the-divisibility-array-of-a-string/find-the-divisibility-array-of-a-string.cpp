class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long  temp=0;
        vector<int>ans(word.size(),0);
        for(int i=0;i<word.size();i++){
            int r=(temp*10+(word[i]-'0'))%m;
            if(r==0) ans[i]=1;
            temp=r;
        }
        return ans;
        
    }
};