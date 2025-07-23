class Solution {
public:
    int count_ab(string& s) {
        stack<char> st;
        int cnt = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                cnt++;
            } else {
                st.push(c);
            }
        }

        string temp = "";
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;
        return cnt;
    }

    int count_ba(string& s) {
        stack<char> st;
        int cnt = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                cnt++;
            } else {
                st.push(c);
            }
        }

        string temp = "";
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;
        return cnt;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x > y) {

            ans += x * count_ab(s);
            ans += y * count_ba(s);
        } else {

            ans += y * count_ba(s);
            ans += x * count_ab(s);
        }
        return ans;
    }
};
