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
    pair<bool, int> getHeightAndBalanced(TreeNode* root){
        if(root == NULL){
            return {true, 0};
        }
        pair<bool, int> leftAns = getHeightAndBalanced(root->left);
        pair<bool, int> rightAns = getHeightAndBalanced(root->right);
        if(leftAns.first && rightAns.first && abs(leftAns.second-rightAns.second)<=1){
            return {true, 1+max(leftAns.second,rightAns.second)};
        }else{
            return {false, 0};
        }
    }
    
public:
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = getHeightAndBalanced(root);
        return ans.first;
    }
};