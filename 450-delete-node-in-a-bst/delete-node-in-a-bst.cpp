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
    TreeNode* solve(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->val==key) {
            if(!root->left && !root->right) return NULL;
            if(root->left && !root->right) return root->left;
            if(!root->left &&  root->right) return root->right;
            else{
                TreeNode* temp=root->left;
                while(temp->right){
                    temp=temp->right;

                }
                root->val=temp->val;
                  root->left = solve(root->left, temp->val);
                
                return root;
            }
        }
       if(key>root->val){
         root->right=solve(root->right,key);
       }
       else{
        root->left=solve(root->left,key);
       }
       return root;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
        
        
    }
};