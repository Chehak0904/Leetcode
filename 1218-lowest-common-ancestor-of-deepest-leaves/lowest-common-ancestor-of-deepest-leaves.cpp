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
    void depth(TreeNode* root,unordered_map<int,int>&mp,int d,int &maxd){
        if(root==NULL) return ;
        maxd=max(maxd,d);
        mp[root->val]=d;
        depth(root->left,mp,d+1,maxd);
        depth(root->right,mp,d+1,maxd);
    }
    TreeNode* solve(TreeNode* root,unordered_map<int,int>&mp,int maxd){
        if(root==NULL) return root;
        if(mp[root->val]==maxd) return root;
        TreeNode* left=solve(root->left,mp,maxd);
        TreeNode * right=solve(root->right,mp,maxd);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxd=0;
        depth(root,mp,0,maxd);
        return solve(root,mp,maxd);
        
    }
};