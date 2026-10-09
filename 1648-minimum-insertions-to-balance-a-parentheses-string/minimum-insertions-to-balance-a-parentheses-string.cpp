class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int ans = 0;
        int count=0;

        for (int i=0;i<n;i++) {
            char ch=s[i];
            if (ch == '(') {
                count++;
            }
            else{
                if(count>0) count--;
                else ans++;
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                else ans++;

            }
        }

        

        return ans+count*2;
    }
};