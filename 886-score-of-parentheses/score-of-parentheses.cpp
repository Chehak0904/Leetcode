class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;

        for (char ch : s) {
            if (ch == '(') {
                st.push("(");
            } else {
                if (st.top() == "(") {
                    st.pop();
                    st.push("1");
                } else {
                    int temp = 0;
                    while (!st.empty() && st.top() != "(") {
                        temp += stoi(st.top()); 
                        st.pop();
                    }
                    st.pop(); 
                    st.push(to_string(2 * temp)); 
                }
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};
