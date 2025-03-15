
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited)) 
                    return true;
               
            } 
            else return true;
        }

        return false;
    }

    bool isCyclic(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
           
                if (dfs(i, adj, visited)) 
                    return true;
            
        }
        return false;
    }
};
