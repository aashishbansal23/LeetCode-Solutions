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
    int diameterOfBinaryTreeHelp(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        int leftAns = diameterOfBinaryTreeHelp(root->left, ans);
        int rightAns = diameterOfBinaryTreeHelp(root->right, ans);
        int height = 1+max(leftAns, rightAns);
        ans = max(ans, leftAns+rightAns);
        return height;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameterOfBinaryTreeHelp(root, ans);
        return ans;
    }
};