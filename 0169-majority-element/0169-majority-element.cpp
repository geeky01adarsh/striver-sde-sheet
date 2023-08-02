class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int temp=nums[0];
        int c=1, n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==temp) c++;
            else{
                c--;
                if(c==0) temp=nums[i], c=1; 
            }
        }
        // c=0;
        // for(auto i:nums) if(i==temp) c++;
        return temp;
    }
};