class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>v;
        int ones=0;
        int zeros=0;
        for(char ch:s){
            if(ch=='0'){
                zeros++;
            }
            else{
                    if(zeros>0){
                      cout<<zeros;
                      v.push_back(zeros);
                    }
                    
                    zeros=0;
                    ones++;
                
            }
        }
        if(zeros>0){
                      cout<<zeros;
                      v.push_back(zeros);
                    }
                    
        int maxi=0;
        for(int i=1;i<v.size();i++){
            maxi=max(v[i]+v[i-1],maxi);
        }
        return maxi+ones;
        
    }
};