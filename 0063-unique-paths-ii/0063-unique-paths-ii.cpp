class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        // int mod = 1e9+7;
        int n=mat.size(), m =mat[0].size();
        vector<int> dp(m, 0);
        // cout<<m<<endl;
    for(int i=0; i<m; i++){
        if(mat[0][i]==1) break;
        dp[i]=1; 
    }
    for(int i=1; i<n; i++){
        vector<int> temp(m, 0);
        for(int j=0; j<m; j++){
            // if(!i&&!j)continue;
            // if(mat[i-1][j]!=-1) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(mat[i][j]==1) continue;
            if(mat[i-1][j]!=1) temp[j]=(temp[j]+dp[j]);
            if(j>0 && mat[i][j-1]!=1) temp[j] = (temp[j]+temp[j-1]);
        }
        dp=temp;
    }
    return dp[m-1];
    }
};