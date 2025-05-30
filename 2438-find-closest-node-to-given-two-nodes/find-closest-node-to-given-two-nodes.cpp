class Solution {
public:
    vector<int> bfs(vector<int>& edges, int node) {
        int n = edges.size();
        vector<int> dist(n, -1);
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({node, 0});
        visited[node] = true;

        while (!q.empty()) {
            auto [curr, d] = q.front();
            q.pop();
            dist[curr] = d;
            int next = edges[curr];
            if (next != -1 && !visited[next]) {
                q.push({next, d + 1});
                visited[next] = true;
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = bfs(edges, node1);
        vector<int> dist2 = bfs(edges, node2);

        int minDistance = INT_MAX;
        int result = -1;

        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDistance) {
                    minDistance = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
