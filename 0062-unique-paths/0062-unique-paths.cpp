class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0) return 1;
        if(m<0 ||  n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=helper(m-1, n, dp)+helper(m, n-1, dp);
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return helper(m-1, n-1, dp);
        vector<int> dp(m, 0);
        // dp[0] = 1;
        for(int i=0; i<m; i++) dp[i]=1;        
        // for(int i=0; i<n; i++) dp[0][i]=1;

        for(int i=1; i<n; i++){
            vector<int> temp(m, 0);
            temp[0]= dp[0];
            for(int j=1; j<m; j++){
                temp[j] = temp[j-1]+dp[j];
            }
            dp=temp;
        }
        return dp[m-1];
        
    }
};