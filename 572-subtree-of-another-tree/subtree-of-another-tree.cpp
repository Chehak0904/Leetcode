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
    bool check(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2) return true;
        if(root1 && !root2) return false;
        if(!root1 && root2) return false;
        if(root1->val!=root2->val) return false;
         bool l=check(root1->left,root2->left);
         bool r=check(root1->right,root2->right);
         return l && r;   
    }
    void func(TreeNode* root,TreeNode* subRoot ,bool &flag){
        if(!root) return ;
        if(root->val==subRoot->val){
            if(check(root,subRoot)){
                flag=true;
            }
        }
        func(root->left,subRoot,flag);
        func(root->right,subRoot,flag);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag=false;
        func(root,subRoot,flag);
        if(flag) return true;
        return false;
        
    }
};