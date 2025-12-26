class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int ansIdx = -1;
        int mini = INT_MAX;
        int countY = 0;
        int countN = 0;
        for (char ch : customers) {
            if (ch == 'Y')
                countY++;
        }
        for (int i = 0; i <= customers.size(); i++) {
            int penalty = countY + countN;
            if (penalty < mini) {
                mini = penalty;
                ansIdx = i;
            }
            if (i < n) {
                if (customers[i] == 'N') {
                    countN++;
                } else {
                    countY--;
                }
            }
        }
        return ansIdx;
    }
};