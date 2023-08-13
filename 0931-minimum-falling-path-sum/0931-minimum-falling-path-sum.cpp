class Solution {
public:
    int helper(int n, int m, vector<vector<int>> & matrix, vector<vector<int>> &dp){
        int sz=matrix.size()-1;
        if(m<0 || m>sz) return INT_MAX;
        if(n==0) return matrix[n][m];
        if(dp[n][m]!=INT_MAX) return dp[n][m];
        return dp[n][m] = matrix[n][m]+min(min(helper(n-1, m-1, matrix,dp), helper(n-1, m, matrix,dp)), helper(n-1, m+1, matrix, dp));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        for(int i=0; i<n; i++){
            ans = min(ans, helper(n-1, i, matrix, dp));
        }
        return ans;
    }
    
    
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int ans = INT_MAX;
    //     vector<int> dp=matrix[0];
    //     // dp=matrix[0];
    //     for(int i=1; i<n; i++){
    //         // ans = min(ans, helper(n-1, i, matrix, dp));
    //         vector<int> temp(n,0);
    //         for(int j=0; j<n; j++){
    //             int tp = INT_MAX;
    //             if(j>0) tp=dp[j-1];
    //             if(j<(n-1)) tp = min(dp[j+1], tp);
    //             temp[j] += min(dp[j], tp);
    //         }
    //         dp=temp;
    //     }
    //     for(int i=0; i<n; i++) ans=min(dp[i], ans);
    //     return ans;
    // }
};