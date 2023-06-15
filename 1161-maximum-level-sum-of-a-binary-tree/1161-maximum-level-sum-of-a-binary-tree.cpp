/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN;
        int max_level = -1, level=1;
        while(q.size()){
            int n = q.size();
            int levelsum=0;
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                levelsum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(levelsum>maxi) maxi=levelsum, max_level=level;
            level++;
        }
        return max_level;
    }
};