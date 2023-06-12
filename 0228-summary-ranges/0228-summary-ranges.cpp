class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int curr;
        string temp="";
        vector<string> ans;
        if(!n) return ans;
        for(int i=0; i<n; i++){
            if(!temp.size()) temp=to_string(nums[i]);
            else if(nums[i]<=nums[i-1]+1) continue;
            else{
                if(temp.size() && stoi(temp)==nums[i-1]) ans.push_back(temp);
                else ans.push_back(temp+"->"+to_string(nums[i-1]));
                // temp="";
                temp=to_string(nums[i]);
            }       
        }
        if(temp.size() && stoi(temp)==nums[n-1]) ans.push_back(temp);
        else ans.push_back(temp+"->"+to_string(nums[n-1]));
        return ans;
    }
};