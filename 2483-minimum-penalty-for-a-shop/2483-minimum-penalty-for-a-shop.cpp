class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = customers.size(), sz =customers.size();
        int n=0, y=0;
        for(int i=sz-1; i>=0; i--){
            if(customers[i]=='N'){
                n++;
                if(n>=y) ans = i, n=0, y=0;
                // else if(n==y && ans==sz) ans=i;
            }
            else y++;
        }
        return ans;
    }
};