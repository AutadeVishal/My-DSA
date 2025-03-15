class Solution {
  public:
  bool dfs(int start,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&parent){
      visited[start]=true;
      for(int neighbor:adj[start]){
          if(!visited[neighbor]){
              parent[neighbor]=start;
              if(dfs(neighbor,adj,visited,parent)) return true;
          }
          else if(neighbor!=parent[start]) return true;
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool>visited(adj.size(),false);
        vector<int>parent(adj.size(),-1);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
               bool iscyclic= dfs(i,adj,visited,parent);
               if(iscyclic) return true;
            }
        }
        return false;
    }
};
