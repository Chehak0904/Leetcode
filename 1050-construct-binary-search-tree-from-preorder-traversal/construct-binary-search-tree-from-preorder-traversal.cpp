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
    TreeNode* solve(vector<int>& preorder, int &idx, int mini, int maxi) {
        if(idx==preorder.size()){
            return NULL;
        }

        int val=preorder[idx];
        if(val<=mini || val>=maxi ){
            return NULL;
        }
        idx++;
        TreeNode* root=new TreeNode(val);
        root->left=solve(preorder,idx,mini,val);
        root->right=solve(preorder,idx,val,maxi);
        return root;

       
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(preorder,idx,INT_MIN,INT_MAX);

    }
};