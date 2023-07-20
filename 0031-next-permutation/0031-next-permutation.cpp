class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // int temp=nums[n];
        int flag=n;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) {flag = i; break;}
        }
        cout<<flag;
        if(flag==n){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1; i>flag; i--){
            if(nums[i]>nums[flag]){
                swap(nums[i], nums[flag]);
                reverse(nums.begin()+(flag+1), nums.end());
                break;
            }
        }
        // if(flag) reverse(nums.begin(), nums.end());
        return;
    }
};