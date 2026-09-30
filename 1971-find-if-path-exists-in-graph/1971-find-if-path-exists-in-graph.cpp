class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        // Step 1: Create adjacency list
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: BFS setup
        queue<int> q;
        vector<bool> visited(n, false);

        visited[source] = true;
        q.push(source);

        // Step 3: BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // If we reached destination
            if (node == destination)
                return true;

            // Explore neighbours
            for (int neighbor : adj[node]) {

                if (!visited[neighbor]) {

                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Destination was not reachable
        return false;
    }
};