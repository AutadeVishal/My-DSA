//bottom up
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size(),INT_MAX);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<height.size();i++){
            
            
            
            if(dp[i]>abs(height[i]-height[i-1])+dp[i-1])dp[i]=abs(height[i]-height[i-1])+dp[i-1];
            if(dp[i]>abs(height[i]-height[i-2]) + dp[i-2])dp[i]=abs(height[i]-height[i-2])+dp[i-2];
            
        }
        
        return dp[height.size()-1];
    }
};
