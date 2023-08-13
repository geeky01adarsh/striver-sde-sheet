class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int  n = grid.size(), m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<int> dp(n, 0);
        dp[0]=1;
        for(int i=1; i<n; i++) {
            if(grid[i][0]==1) break; 
            dp[i]=1;
        }
        for(int i=1; i<m; i++){
            vector<int> temp(n, 0);
            if(grid[0][i]!=1) temp[0]= dp[0];
            for(int j=1; j<n; j++){
                if(grid[j][i]==1) continue;
                temp[j] = temp[j-1]+dp[j];
            }
            dp=temp;
        }
        return dp[n-1];
    }
};