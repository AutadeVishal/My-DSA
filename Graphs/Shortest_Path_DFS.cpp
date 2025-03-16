class Solution {
  public:
  void findpath(vector<vector<int>>&adj,int src,int &dest,int count,int &shortestcount,vector<bool>&visited){
     
      if(src==dest){
          shortestcount=min(count,shortestcount);
          return ;
      }
       visited[src]=true;
         for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                findpath(adj, neighbor, dest, count + 1, shortestcount, visited);
            }
        }
       visited[src]=false;
      
  }
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          vector<int> ans(adj.size(), INT_MAX);
        
        for (int i = 0; i < adj.size(); i++) {
            if (i == src) {
                ans[i] = 0;
                continue;
            }
            vector<bool> visited(adj.size(), false);
            int shortestcount = INT_MAX;
            findpath(adj, src, i, 0, shortestcount, visited);
            ans[i] = (shortestcount == INT_MAX) ? -1 : shortestcount;
        }
        
        return ans;
    }
};
