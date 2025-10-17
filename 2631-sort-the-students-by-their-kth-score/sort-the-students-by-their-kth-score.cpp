int t;
bool comparator(vector<int>& a, vector<int>& b) { return a[t] > b[t]; }
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        t = k;
        sort(score.begin(), score.end(), comparator);
        return score;
    }
};