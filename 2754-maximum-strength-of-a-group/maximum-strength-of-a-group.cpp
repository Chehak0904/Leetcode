class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        int cnt=0;
        for(int num:nums){
            if(num>0) pos.push_back(num);
            if(num<0) neg.push_back(num);
            if(num==0) cnt++;
        }
        long long ans=1;
        for(int i=0;i<pos.size();i++) ans*=pos[i];
        int i=(neg.size()%2==0)?0:1;
        sort(neg.begin(),neg.end());
        reverse(neg.begin(),neg.end());
        for(;i<neg.size();i++){
            ans*=neg[i];
        }
        if(neg.size()==1&& pos.size()==0 && cnt>0) return 0;
        if(neg.size()==1 && pos.size()==0 && cnt==0) return neg[0];
        if(neg.size()==0 && pos.size()==0 && cnt>0) return 0;
        return ans;


        
    }
};