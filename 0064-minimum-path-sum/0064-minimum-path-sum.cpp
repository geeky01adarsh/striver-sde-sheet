class Solution {
public:
    int helper(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m] = grid[n][m]+min(helper(n-1,m,grid,dp), helper(n, m-1, grid, dp));
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return helper(n-1, m-1, grid, dp);
        
//         for(int i=1; i<n; i++) dp[i][0] += dp[i-1][0];        
//         for(int i=1; i<m; i++) dp[0][i] += dp[0][i-1];

//         for(int i=1; i<n; i++){
//             for(int j=1; j<m; j++){
//                 dp[i][j]+= min(dp[i-1][j], dp[i][j-1]);
//             }
//         }
// //         for(int i=0; i<n; i++){
            
// //         }
//         return dp[n-1][m-1];
        
        
        // vector<int> dp = grid[0];
        // for(int i=1; i<m; i++) dp[i]+=dp[i-1];
        // for(int i=1; i<n; i++){
        //     vector<int> temp=grid[i];
        //     temp[0] += dp[0];
        //     for(int j=1; j<m; j++){
        //         temp[j] += min(temp[j-1],dp[j]);
        //     }
        //     dp=temp;
        // }
        // return dp[m-1];
    }
};