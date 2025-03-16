class Solution {
  public:
    void solve(queue<int>&q,int &count,vector<int>&indirected,vector<vector<int>>&adj){
      int start;
      while(!q.empty()){
           start=q.front();
           q.pop();
          count++;
           for(int nbor:adj[start]){
             
               indirected[nbor]--;
               if(indirected[nbor]==0){
                   q.push(nbor);
               }
           }
             
      }
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
         vector<int>indirected(adj.size(),0);
       for(int i=0;i<adj.size();i++){
         for(int j=0;j<adj[i].size();j++)
{   if(adj[i][j]==i) return true;
               indirected[adj[i][j]]++;
           }
       }
       
       queue<int>q;
       for(int i=0;i<indirected.size();i++){
           if(indirected[i]==0){
               q.push(i);
           }
       }
       int count=0;
       solve(q,count,indirected,adj);
       return count != adj.size();

    }
};
