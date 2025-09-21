class Solution {
public:
    bool dfs(int n, int col, unordered_map<int, vector<int>>& adj,vector<int>& visited) {
        visited[n] = col;
        for (auto it : adj[n]) {
            if (visited[it] == -1) {
                if (!dfs(it, 1 - col, adj, visited)) {
                    return false;
                }
            } else if (visited[it] == col)
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> visited(n + 1, -1);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int col = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, col, adj, visited))
                    return false;
            }
        }
        return true;
    }
};