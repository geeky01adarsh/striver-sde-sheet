class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(ump.count(target-nums[i])) return {ump[target-nums[i]], i};
            ump[nums[i]]=i;
        }
        return {-1,-1};
    }
};