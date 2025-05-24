class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sr = 0, sc = 0;
        int er = n - 1, ec = n - 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cnt = 1;

        while (sr <= er && sc <= ec) {
            for (int i = sc; i <= ec; i++)
                matrix[sr][i] = cnt++;
            sr++;

            for (int i = sr; i <= er; i++)
                matrix[i][ec] = cnt++;
            ec--;

            if (sr <= er) {
                for (int i = ec; i >= sc; i--)
                    matrix[er][i] = cnt++;
                er--;
            }

            if (sc <= ec) {
                for (int i = er; i >= sr; i--)
                    matrix[i][sc] = cnt++;
                sc++;
            }
        }

        return matrix;
    }
};
