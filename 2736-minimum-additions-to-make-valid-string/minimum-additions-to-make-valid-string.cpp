class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        string temp = "abc";
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (i < n) {
            if (j == 3) {
                j = 0;
            }
            if (word[i] != temp[j]) {
                cnt++;
                j++;

            } else if (word[i] == temp[j]) {
                i++;
                j++;
            }
        }
        while (j < 3) {
            cnt++;
            j++;
        }
        return cnt;
    }
};