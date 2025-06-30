class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            mp[r].insert(c);
        }
        int rem = (n - mp.size()) * 2;
        for (auto it : mp) {
            bool flag = false;
            unordered_set<int> st = it.second;
            if (st.find(2) == st.end() && st.find(3) == st.end() &&
                st.find(4) == st.end() && st.find(5) == st.end()) {
                rem++;
                flag = true;
            }
            if (st.find(6) == st.end() && st.find(7) == st.end() &&
                st.find(8) == st.end() && st.find(9) == st.end()) {
                rem++;
                flag = true;
            }
            if (!flag) {
                if (st.find(4) == st.end() && st.find(5) == st.end() &&
                    st.find(6) == st.end() && st.find(7) == st.end()) {
                    rem++;
                }
            }
        }
        return rem;
    }
};