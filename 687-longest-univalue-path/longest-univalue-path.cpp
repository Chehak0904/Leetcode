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
    int ans=INT_MIN;
    int f(TreeNode* node){
        if(!node) return 0;
        int left=f(node->left);
        int right=f(node->right);
        int leftPath=0,rightPath=0;
        if(node->left && node->left->val==node->val){
              leftPath=1+left;
        }
        if(node->right && node->right->val==node->val){
              rightPath=1+right;
        }
        ans=max(leftPath+rightPath,ans);
        return max(leftPath,rightPath);
    }
    int longestUnivaluePath(TreeNode* root) {
        f(root);
        return ans==INT_MIN?0:ans;
        
    }
};