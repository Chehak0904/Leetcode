class Solution {
public:
    bool compare(string &s1,string&s2){
        int n1=s1.length();
        int n2=s2.length();
        if(n1!=n2+1){
            return false;
        }
        int i=0,j=0;
        while(i<n1){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return (i==n1 && j==n2);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](const string &s1,const string &s2){
                 if(s1.length()!=s2.length()) return s1.length()<s2.length();
                 return s1<s2;
        });
        vector<int>dp(n,1);
        int len=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])&& dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            len=max(dp[i],len);
        }
        return len;
        
    }
};