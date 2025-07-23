class Solution {
public:
    int f(string &temp,char first,char sec,int p){
        int points=0;
        stack<int> st;
        for(char ch:temp){
            if(!st.empty() && st.top()==first && ch==sec){
                st.pop();
                points+=p;
            }
            else{
                st.push(ch);
            }
        }
        temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return points;
    }
    
    int maximumGain(string s, int x, int y) {
        string temp=s;
        int ans=0;
        if(x>y){
            ans+=f(temp,'a','b',x);
            ans+=f(temp,'b','a',y);
        }
        else{
            ans+=f(temp,'b','a',y);
            ans+=f(temp,'a','b',x);
        }
        return ans;
    }
};