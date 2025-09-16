class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char c:s){
            if(st.empty()) st.push({c,1});
            else if(c==st.top().first){
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
            else{
                st.push({c,1});
            }
        }
        string temp="";
        while(!st.empty()){
            char c=st.top().first;
            int cnt=st.top().second;
            st.pop();
            while(cnt--){
                temp.push_back(c);
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};