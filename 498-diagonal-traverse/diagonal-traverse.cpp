class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        map<int, vector<int>> mp;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        int dir = 0;
        for (auto& [it, vec] : mp) {
            if (dir == 0) {
                reverse(vec.begin(), vec.end());
            }
            for (auto v : vec) {
                ans.push_back(v);
            }
            dir = 1 - dir;
        }
        return ans;
    }
};