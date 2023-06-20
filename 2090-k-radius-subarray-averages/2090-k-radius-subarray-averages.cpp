class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        long long sum = 0;
        if(n<2*k) return ans;
        int size = 2*k;
        for(int i=0; i<size; i++){
            sum+=nums[i];
        }
        for(int i=k; i<n-k; i++){
            sum+=nums[i+k];
            ans[i] = sum/(size+1);
            sum -= nums[i-k];
        }
        
        return ans;
    }
};