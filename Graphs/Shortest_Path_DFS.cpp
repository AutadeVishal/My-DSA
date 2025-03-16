class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, int count, vector<int>& dist, vector<bool>& visited) {
       
        if (count >= dist[node]) return;
        dist[node] = count;
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(adj, neighbor, count + 1, dist, visited);
            }
        }

        visited[node] = false; 
    }

    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);  
        vector<bool> visited(n, false);  

        dfs(adj, src, 0, dist, visited);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
