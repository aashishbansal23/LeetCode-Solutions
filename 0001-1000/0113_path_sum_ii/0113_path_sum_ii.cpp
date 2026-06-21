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
    void pathSumHelp(TreeNode* root, int targetSum, vector<int>& output, vector<vector<int>>& ans){
        if(!root){
            return ;
        }
        output.push_back(root->val);
        targetSum -= root->val;
        if(!root->left && !root->right){
            if(targetSum == 0){
                ans.push_back(output);
            }
            output.pop_back();
            return ;
        }
        pathSumHelp(root->left, targetSum, output, ans);
        pathSumHelp(root->right, targetSum, output, ans);
        output.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        vector<int> output;
        pathSumHelp(root, targetSum, output, ans);
        return ans;
    }
};