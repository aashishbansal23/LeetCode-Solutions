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
    bool checkNum(TreeNode* root, int k){
        if(root == NULL){
            return false;
        }
        if(root->val == k){
            return true;
        }
        if(checkNum(root->left, k)){
            return true;
        }
        return checkNum(root->right, k);
    }
    
    bool findTargetHelp(TreeNode* root, TreeNode* temp, int k){
        if(root==NULL || temp==NULL){
            return false;
        }
        if(k-temp->val!=temp->val && checkNum(root, k-temp->val)){
            return true;
        }
        if(findTargetHelp(root, temp->left, k)){
            return true;
        }
        return findTargetHelp(root, temp->right, k);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        return findTargetHelp(root, root, k);
    }
};