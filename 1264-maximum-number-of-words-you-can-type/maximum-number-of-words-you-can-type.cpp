class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for (char c : brokenLetters) {
            st.insert(c);
        }
        string temp = "";
        int total_count = 0;
        int d = 0;
        bool flag = true;
        for (char c : text) {
            if (c == ' ') {
                total_count++;
                temp = "";
                if (flag == false) {
                    d++;
                    flag = true;
                }
            } else {
                if (st.find(c) != st.end()) {
                    flag = false;
                }
                temp.push_back(c);
            }
        }
        
        if(!temp.empty()){
            total_count++;
            if (flag == false) {
                d++;
                flag = true;
            }
        }
        return total_count - d;
    }
};
