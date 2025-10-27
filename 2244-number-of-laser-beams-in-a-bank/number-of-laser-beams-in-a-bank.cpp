class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        vector<int>vec;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j]=='1'){
                    cnt++;
                }
            }
            if(cnt) vec.push_back(cnt);
        }
        int ans=0;
        for(int i=1;i<vec.size();i++){
            ans+=(vec[i]*vec[i-1]);
        }
        return ans;
        
    
        
    }
};