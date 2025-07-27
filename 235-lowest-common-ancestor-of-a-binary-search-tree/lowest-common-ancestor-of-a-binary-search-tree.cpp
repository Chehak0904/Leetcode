/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode* r,TreeNode* p,TreeNode* q){
        // if(!root)return NULL;
        if(p->val<r->val && q->val<r->val) return f(r->left,p,q);
        if(p->val>r->val && q->val>r->val) return f(r->right,p,q);
        else return r;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
        
    }
};