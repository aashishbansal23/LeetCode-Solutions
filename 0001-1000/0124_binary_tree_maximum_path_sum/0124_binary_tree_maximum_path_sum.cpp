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
    int maxPathSumHelp(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        int leftAns = maxPathSumHelp(root->left, ans);
        int rightAns = maxPathSumHelp(root->right, ans);
        
        int temp = root->val+leftAns+rightAns;
        temp = max(temp, root->val+max(leftAns, rightAns));
        temp = max(temp, root->val);
        ans = max(ans, temp);
        
        return max(root->val, root->val+max(leftAns, rightAns));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumHelp(root, ans);
        return ans;
    }
};