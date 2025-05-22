class Solution {
public:
    void parent(TreeNode* root, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL) return;
        mp[root] = par;
        parent(root->left, root, mp);
        parent(root->right, root, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        parent(root, NULL, mp);

        unordered_map<TreeNode*, bool> visited;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while (!q.empty() && k--) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left && !visited[temp->left]) {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }

                if (temp->right && !visited[temp->right]) {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }

                if (mp[temp] && !visited[mp[temp]]) {
                    visited[mp[temp]] = true;
                    q.push(mp[temp]);
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
