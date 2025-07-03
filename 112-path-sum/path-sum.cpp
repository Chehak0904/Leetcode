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
    bool solve(TreeNode* root, int target, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == target)
                return true;
            return false;
        }
        sum += root->val;

        bool leftSum = solve(root->left, target, sum);
        bool rightSum = solve(root->right, target, sum);
        return leftSum || rightSum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};