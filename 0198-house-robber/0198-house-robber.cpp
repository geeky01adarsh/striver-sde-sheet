class Solution {
public:
    
    int dpp(int n, vector<int>&nums,vector<int>&dp){
        if(n<0) return 0;
        if(n==0||n==1) return nums[n];
        if (dp[n]!=-1) return dp[n];
        
        return dp[n]= max(nums[n]+max(dpp(n-2, nums,dp),dpp(n-3,nums,dp)),dpp(n-1, nums,dp));
        
        
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(nums.size()==2) return max(nums[0], nums[1]);
        return dpp(nums.size()-1,nums,dp);
        // cout<<dp[0]<<" "<<dp[1]<<endl;
        return dp[nums.size()-1];
    }
};