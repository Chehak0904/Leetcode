class Solution {
public:
    void f(int idx, int target, vector<int>& candidates, vector<int>& temp,
           vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx >= candidates.size())
            return;
        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            f(idx, target - candidates[idx], candidates, temp, ans);
            temp.pop_back();
        }

        f(idx + 1, target, candidates, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(0, target, candidates, temp, ans);
        return ans;
    }
};