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
    TreeNode* solve(TreeNode* root,unordered_set<int>st,vector<TreeNode*>&v){
        if(root==NULL) return NULL;
        root->left=solve(root->left,st,v);
        root->right=solve(root->right,st,v);
        if(st.find(root->val)!=st.end()){
            if(root->left) v.push_back(root->left);
            if(root->right) v.push_back(root->right);
            return NULL;
        }
        return root;




    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>v;
        unordered_set<int>st;
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        TreeNode* ans=solve(root,st,v);
        if(ans!=NULL){
            v.push_back(ans);
        }
        return v;

        
    }
};