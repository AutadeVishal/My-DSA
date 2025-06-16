// Memoisation
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(int i,vector<int>&dp,vector<int>&arr){
        if(i==0)return dp[0]=arr[0];
        if(dp[i]!=0) return dp[i];
        if(i==1) return max(arr[0],arr[1]);
        int included=arr[i]+solve(i-2,dp,arr);
        int excluded=solve(i-1,dp,arr);
        return dp[i]=max(included,excluded);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size(),0);
     int x=solve(arr.size()-1,dp,arr);
        return x;
    }
};

//tabulation
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        pair<int,int>p={0,0};
        for(int i=0;i<arr.size();i++){
            int left=arr[i]+p.second;
            int right=max(p.first,p.second);
            p.first=left;
            p.second=right;
        }
        return max(p.first,p.second);
    }
};
