class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+1, 0);
        for(int i=0; i<n; i++){
            if(arr[nums[i]]) return nums[i];
            arr[nums[i]] = 1;
        }
        return -1;
    }
};