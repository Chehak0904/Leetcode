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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>inorder;
        while(curr!=NULL){
            if(curr->left){
                TreeNode* temp=curr->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                temp->right=curr;
                TreeNode* prev=curr;
                curr=curr->left;
                prev->left=NULL;

            }
            else{
                inorder.push_back(curr->val);
                curr=curr->right;

            }

        }
        return inorder;
        
    }
};