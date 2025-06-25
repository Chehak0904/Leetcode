class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> arr(n, 0); // will show how much shift will be there

        for (int i = 0; i < shifts.size(); i++) {
            int left_idx = shifts[i][0];
            int right_idx = shifts[i][1];
            int dir = shifts[i][2];
            if (dir == 0) {
                arr[left_idx] -= 1;
                if (right_idx + 1 < n) {
                    arr[right_idx + 1] += 1;
                }
            } else {
                arr[left_idx] += 1;
                if (right_idx + 1 < n) {
                    arr[right_idx + 1] -= 1;
                }
            }
        }

        string ans = "";
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int shift = (s[i] - 'a' + sum) % 26;
            if (shift < 0) shift += 26;  
            ans.push_back('a' + shift);
        }

        return ans;
    }
};
