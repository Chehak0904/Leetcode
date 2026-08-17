class Solution {
public:
    void solve(Node* root) {
        if (root == NULL) return;

        if (root->left) {
            root->left->next = root->right;
        }

        if (root->next && root->right) {
            root->right->next = root->next->left;
        }
        else if(root->right) {
            root->right->next = NULL;
        }

        solve(root->left);
        solve(root->right);
    }

    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        root->next = NULL;
        solve(root);

        return root;
    }
};