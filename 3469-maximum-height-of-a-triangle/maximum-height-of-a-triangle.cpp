class Solution {
public:
    int solve(int col1, int col2) {
        int i = 0;
        int cnt = 1;
        while (true) {
            if (i % 2 == 0) {
                if (col1 - cnt >= 0) {
                    col1 -= cnt;
                    cnt++;
                    i++;
                } else {
                    break;
                }

            } else {
                if (col2 - cnt >= 0) {
                    col2 -= cnt;
                    cnt++;
                    i++;

                } else {
                    break;
                }
            }
        }
        return cnt-1;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
};