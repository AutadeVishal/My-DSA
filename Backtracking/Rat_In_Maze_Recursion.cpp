//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
void solve(vector<vector<int>>&mat,vector<vector<int>>&v,int x,int y,vector<string>&ans,string output){
      if(x==(mat.size()-1) && y==(mat.size()-1)){
          ans.push_back(output);
          return;
      }
      v[x][y]=1;
  
      if(x-1>=0 && v[x-1][y]==0 && mat[x-1][y]){
          output.push_back('U');
          solve(mat,v,x-1,y,ans,output);
          output.pop_back();
      }
      if(x+1<mat.size() && v[x+1][y]==0 && mat[x+1][y]){
          output.push_back('D');
          solve(mat,v,x+1,y,ans,output);
          output.pop_back();
      }
  
        if(y-1>=0 && v[x][y-1]==0 && mat[x][y-1]==1){
          output.push_back('L');
          solve(mat,v,x,y-1,ans,output);
          output.pop_back();
      }
      if(y+1<mat.size() && v[x][y+1]==0 && mat[x][y+1]){
          output.push_back('R');
          solve(mat,v,x,y+1,ans,output);
          output.pop_back();
      }
      v[x][y]=0;
}
    vector<string> findPath(vector<vector<int>> &mat) {
      vector<vector<int>> v(mat.size(), vector<int>(mat.size(), 0)); 
      int n=mat.size()-1;
      if(mat[0][0]==0 || mat[n][n]==0)return {};
       string output="";
       vector<string>ans;
       solve(mat,v,0,0,ans,output);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
