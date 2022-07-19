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
    void sumNumbersHelp(TreeNode* root, int& output, int& ans){
        if(!root){
            return ;
        }
        output *= 10;
        output += root->val;
        if(!root->left && !root->right){
            ans += output;
            output /= 10;
            return ;
        }
        sumNumbersHelp(root->left, output, ans);
        sumNumbersHelp(root->right, output, ans);
        output /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int output = 0;
        sumNumbersHelp(root, output, ans);
        return ans;
    }
};