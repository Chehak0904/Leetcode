/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&dp){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        int nt=solve(root->left,dp)+solve(root->right,dp);
        int a=(root->left)?solve(root->left->left,dp)+solve(root->left->right,dp):0;
        int b=(root->right)?solve(root->right->left,dp)+solve(root->right->right,dp):0;
        int take=root->val+a+b;
        return dp[root]=max(take,nt);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return solve(root,dp);
        
    }
};