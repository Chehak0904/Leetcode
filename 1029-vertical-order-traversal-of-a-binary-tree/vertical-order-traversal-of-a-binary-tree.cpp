/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int h, int l,
               map<pair<int, int>, vector<int>>& mp) {
        if (root == NULL) {
            return;
        }
        mp[{h, l}].push_back(root->val);
        solve(root->left, h - 1, l + 1, mp);
        solve(root->right, h + 1, l + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> mp;
        solve(root, 0, 0, mp);

        map<int, vector<int>> sorted;

        for (auto& it : mp) {
            int h = it.first.first;

            vector<int>& temp = it.second;
            sort(temp.begin(), temp.end());
            for (int val : temp) {
                sorted[h].push_back(val);
            }
        }

        vector<vector<int>> ans;
        for (auto& it : sorted) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
