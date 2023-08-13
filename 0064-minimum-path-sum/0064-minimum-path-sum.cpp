class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> dp=grid;
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
        
        
        vector<int> dp = grid[0];
        for(int i=1; i<m; i++) dp[i]+=dp[i-1];
        for(int i=1; i<n; i++){
            vector<int> temp=grid[i];
            temp[0] += dp[0];
            for(int j=1; j<m; j++){
                temp[j] += min(temp[j-1],dp[j]);
            }
            dp=temp;
        }
        return dp[m-1];
    }
};