class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int l=0, r=1;
        int cnt=1;
        int alpha=-1;
        while(l<n && r<n){
            if(num[l]!=num[r]){
                l=r;
                cnt=1;
            }
            else{
                cnt++;
            }
            if(cnt>=3){
                int d=num[l]-'0';
                alpha=max(d,alpha);
            }
            r++;
        }
        string res="";
        if(alpha==-1) return res;
        for(int i=0;i<3;i++){
            char c=alpha+'0';
            res+=c;
        }
        return res;
    }
};