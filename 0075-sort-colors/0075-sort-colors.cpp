class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, k=nums.size()-1, n = nums.size();
        for(int j=0; j<n; j++){
            if(nums[j]!=0) break;
            i++;
        }
        for(int j=n-1; j>=0; j--){
            if(nums[j]!=2) break;
            k--;
        }
        for(int j=i; j<=k;){
            if(nums[j]==0) swap(nums[i++], nums[j++]);
            else if(nums[j]==2){ 
                swap(nums[k--], nums[j]);
            }
            else j++;
        }
        
    }
};