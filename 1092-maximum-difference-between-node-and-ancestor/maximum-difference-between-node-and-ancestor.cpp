class Solution {
public:
    pair<int,int> solve(TreeNode* root, int &ans) {
        if (!root) return {INT_MAX, INT_MIN};

        auto l = solve(root->left, ans);
        auto r = solve(root->right, ans);

        int mini = min(l.first, r.first);
        int maxi = max(l.second, r.second);

        
        if (mini != INT_MAX) ans = max(ans, abs(root->val - mini));
        if (maxi != INT_MIN) ans = max(ans, abs(root->val - maxi));

        return {min(mini, root->val), max(maxi, root->val)};
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
