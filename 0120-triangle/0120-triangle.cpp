class Solution {
public:
    // int helper(int n, int m, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    //     // int sz = triangle.size();
    //     if(n==0) return triangle[0][0];
    //     if(m<0 || m>n) return INT_MAX;
    //     if(dp[n][m]!=-1) return dp[n][m];
    //     return dp[n][m]=triangle[n][m] + min(helper(n-1,m,triangle, dp), helper(n-1, m-1, triangle,dp));
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     int ans = INT_MAX;
    //     vector<vector<int>> dp;
    //     for(int i=0; i<n; i++){
    //         vector<int> temp(i+1, -1);
    //         dp.push_back(temp);
    //     }
    //     for(int i=0; i<n; i++){
    //         ans = min(ans, helper(n-1, i, triangle, dp));
    //     }
    //     return ans;
    // }
    
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        int ans = INT_MAX;
        vector<vector<int>> dp=triangle;
        
        for(int i=1; i<n; i++){
            dp[i][0]+=dp[i-1][0];
            dp[i][i]+=dp[i-1][i-1];
            for(int j=1; j<i; j++){
                dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
        
        for(int i=0; i<n; i++) ans = min(ans, dp[n-1][i]);
        return ans;
    }
};